#include <vector>
#include <cmath>
#include <iostream>

class Matrix {
private:
    std::vector<std::vector<double>> A;
    int n;

public:
    Matrix(double* arr, int size) {
        n = size;
        A.assign(n, std::vector<double>(n + 1));
        int idx = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n + 1; j++)
                A[i][j] = arr[idx++];
    }
    std::vector<double> solve() {
        for (int i = 0; i < n; i++) {
            double maxEl = std::abs(A[i][i]);
            int maxRow = i;
            for (int k = i + 1; k < n; k++) {
                if (std::abs(A[k][i]) > maxEl) {
                    maxEl = std::abs(A[k][i]);
                    maxRow = k;
                }
            }
            std::swap(A[maxRow], A[i]);
            for (int k = i + 1; k < n; k++) {
                double c = -A[k][i] / A[i][i];
                for (int j = i; j < n + 1; j++) {
                    if (i == j)
                        A[k][j] = 0;
                    else
                        A[k][j] += c * A[i][j];
                }
            }
        }
        std::vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) {
            x[i] = A[i][n] / A[i][i];
            for (int k = i - 1; k >= 0; k--) {
                A[k][n] -= A[k][i] * x[i];
            }
        }

        return x;
    }
};

extern "C" {
    double* solve_system(double* a, int n) {
        Matrix M(a, n);
        std::vector<double> result = M.solve();
        double* out = new double[n];
        for (int i = 0; i < n; i++)
            out[i] = result[i];

        return out;
    }
}
