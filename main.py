import ctypes

lib = ctypes.CDLL("./libmatrix.so")
lib.solve_system.restype = ctypes.POINTER(ctypes.c_double)

def get_input():
    n = int(input("Enter number of variables: "))
    matrix = []
    print("Enter augmented matrix row by row:")
    for _ in range(n):
        matrix.extend(map(float, input().split()))
    return n, matrix

def solve():
    n, matrix = get_input()
    arr = (ctypes.c_double * len(matrix))(*matrix)
    result_ptr = lib.solve_system(arr, n)
    solution = [result_ptr[i] for i in range(n)]
    print("Solution: ", solution)

if __name__ == "__main__":
    solve()
