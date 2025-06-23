과제 071 - Matrix
Requested files: main.cpp, Matrix.hpp, Matrix.cpp (다운로드)
제출 방식: 개인
Goal
The goal of this programming exercise is to help students practice the definition and usage of operator overloading in C++ by implementing a custom Matrix class that supports various mathematical operations. Students will work with initializer lists, dynamic memory, and common matrix algorithms such as inversion and multiplication. This exercise aligns with the curriculum’s focus on classes, operator overloading, and STL usage in C++17.

Concept Explanation
To complete this problem, students must understand the following key C++ concepts:

Operator Overloading: Custom implementation of operators (e.g., +, -, *, ==, !=) for user-defined types.
Dynamic Memory Management: Managing memory manually using new and delete to ensure deep copying and efficient resource use.
Initializer Lists: Using std::initializer_list to allow matrix objects to be initialized like {{1, 2}, {3, 4}}.
Matrix Algebra: Understanding matrix operations such as addition, subtraction, multiplication, and inversion (2x2 and 3x3 only).
Specifically, students will implement a matrix class capable of:

Creating matrices via initializer lists or dimensions
Overloading arithmetic operators for element-wise and dot product operations
Checking matrix equality
Calculating inverses for 2x2 and 3x3 square matrices
Classes or Functions to Implement
Class: Matrix

Private Member Variables:
int* data : Pointer to dynamically allocated 1D array storing matrix elements in row-major order.
size_t row : Number of rows in the matrix.
size_t col : Number of columns in the matrix.
Public Member Functions:
Matrix() : Default constructor (creates an empty matrix).
Matrix(size_t r, size_t c) : Constructs an empty matrix of given size initialized with zeros.
Matrix(std::initializer_list<std::initializer_list<int>>) : Constructs matrix using nested initializer lists.
Matrix(const Matrix&) : Copy constructor (deep copy).
Matrix& operator=(const Matrix&) : Copy assignment operator.
~Matrix() : Destructor that deallocates memory.
Matrix operator+(const Matrix&) const : Matrix addition.
Matrix operator-(const Matrix&) const : Matrix subtraction.
Matrix operator*(const Matrix&) const : Matrix multiplication (dot product).
bool operator==(const Matrix&) const : Element-wise matrix equality.
bool operator!=(const Matrix&) const : Element-wise matrix inequality.
Matrix inverse() const : Calculates the inverse of 2x2 or 3x3 matrix.
Friend Functions:
std::ostream& operator<<(std::ostream&, const Matrix&) : Prints matrix with formatting.
Constraints
Matrix inversion is only implemented for 2x2 and 3x3 square matrices.
All arithmetic operations (+, -, *) are only valid when matrices are compatible in size.
Matrix elements are integers.
If the determinant is 0 or the matrix is not square, inverse() should return an empty matrix.
Matrix addition/subtraction require same dimensions. Matrix multiplication requires A.cols == B.rows.
Submission Files
Matrix.h : Class declaration with all method signatures.
Matrix.cpp : Class implementation with all logic and operator overloads.
Input/Output Example
===== 2x2 Matrix Tests =====
m2a
| 4 1 |
| -7 -3 |
m2b
| 1 1 |
| 0 0 |
m2c = m2a + m2b
| 5 2 |
| -7 -3 |
m2c.inverse
| 3 2 |
| -7 -5 |

===== 3x3 Matrix Tests =====
m3a
| 2 3 0 |
| 1 -2 -1 |
| 2 0 -1 |
m3b
| -1 -1 3 |
| -1 2 5 |
| 3 6 1 |
m3c = m3a + m3b
| 1 2 3 |
| 0 0 4 |
| 5 6 0 |
m3c.inverse
| |
m3d = m3a.inverse + [[0,0,0],[0,0,0],[0,0,1]]
| 2 3 -3 |
| -1 -2 2 |
| 4 6 -6 |

===== Additional Operator Tests =====
a
| 1 2 |
| 3 4 |
b
| 5 6 |
| 7 8 |
a * b
| 19 22 |
| 43 50 |
a - [[1,1],[1,1]]
| 0 1 |
| 2 3 |
a == a: true
a != d: true
