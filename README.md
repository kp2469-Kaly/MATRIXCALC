# MatrixCalc Solver

A cross-language system of linear equations solver that combines C++ mathematical computation with Python ease-of-use, demonstrating practical multi-paradigm programming.

## Overview

This project implements interoperability between two languages following different programming paradigms:
- **Python (Functional programming)** handles user input, data preparation, and output.
- **C++ (Object-oriented programming)** performs numerical computation using Matrix class and Gaussian elimination.

### Key Features

- Solves systems of n linear equations with n unknowns  
Numerically stable
- High performance (compiled C++ backend)  
- User friendly (Python frontend)  
- Cross-platform compatible  

---

### Prerequisites

- Python
- C++ compiler

### Example Session

```
Enter number of variables: 3
Enter augmented matrix row by row:
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
Solution:  [2.0, 3.0, -1.0]
```

## Project Structure

MATRIXCALC

├── main.py             
├── matrixCalc.cpp      
├── README.md            
└── REPORT.md            

## How It Works

1. Python gathers input and converts it into a C-style array.
2. Python calls the C++ function `solve_system()`
3. C++ constructs a `Matrix` object and performs Gaussian elimination to solve the system.
4. C++ returns the solution vector back to Python as a dynamically allocated array.
5. Python reads and prints the results** to the user.

This project fulfills the Final Project Requirements for Principles of Programming Languages.
