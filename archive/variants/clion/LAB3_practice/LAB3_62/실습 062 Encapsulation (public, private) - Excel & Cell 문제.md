실습 062 Encapsulation (public, private) - Excel & Cell
Requested files: test_Excel.cpp, Excel.h, Excel.cpp, Cell.h, Cell.cpp (다운로드)
제출 방식: 개인
Goal
Implement two C++ classes, Cell and Excel, applying the principle of encapsulation and using a modern C++ coding style. Each Cell should securely manage its data, expose only necessary interfaces, and hide its internal structure completely. The Excel class should interact with Cell instances exclusively through well-designed public methods.

You must use enum class to represent the cell type clearly and safely, and apply STL algorithms and lambda expressions when implementing key functionalities such as range search and average calculation.

Concept Explanation
Encapsulation ensures that an object's internal state is protected from unauthorized access or modification. Only a carefully chosen set of public methods (interfaces) should be exposed. In this project, the Cell class hides all its internal data members and only provides essential methods such as isNumeric(), isString(), getNumericValue(), and toString().

enum class (introduced in C++11) provides type-safe enumerations, avoiding common mistakes from traditional enums.

Students will also practice type aliasing (using using) to simplify complex type names like a 2D vector of cells.

Modern C++ emphasizes the use of STL algorithms (e.g., std::any_of, std::accumulate) and lambda functions for concise and expressive code, which you must apply when implementing the Excel functionalities.

Classes or Functions to Implement
Class: Cell
Private Variables:
CellType type_ — Enum class indicating the type of stored data (STRING, INT, DOUBLE).
std::string stringVal_ — Stores the string value.
int intVal_ — Stores the integer value.
double doubleVal_ — Stores the double value.
Public Functions:
Cell() — Default constructor creating an empty cell.
Cell(const std::string val) — Constructor to create a cell containing a string.
Cell(int val) — Constructor to create a cell containing an integer.
Cell(double val) — Constructor to create a cell containing a double.
bool isNumeric() const — Returns true if the cell contains a numeric value (INT or DOUBLE).
bool isString() const — Returns true if the cell contains a string value.
double getNumericValue() const — Returns the numeric value; non-numeric cells return 0.0.
std::string toString() const — Returns a string representation suitable for output.
Class: Excel
Type Alias:
using Table = std::vector<std::vector<Cell>>; — Defines a more readable alias for a 2D vector of cells.
Private Variables:
Table data_ — Stores the table of cells.
Private Functions:
bool isValidRange(int fromRow, int fromCol, int toRow, int toCol) const — Checks whether the specified range is valid within the table boundaries.
std::vector<Cell> getCellsInRange(int fromRow, int fromCol, int toRow, int toCol) const — Returns all cells in the specified rectangular range.
bool hasStringInRange(int fromRow, int fromCol, int toRow, int toCol) const — Checks if any cell in the specified range is a string.

Public Functions:
Excel(const Table& data) — Constructor initializing the Excel table.
Tip: To check if any cell is a string, use std::any_of with a lambda: cell.isString().

double average(int fromRow, int fromCol, int toRow, int toCol) const — Calculates the average of numeric cells in a specified range; returns 0.0 if any cell in the range is a string.

Tip: To sum up numeric values, use std::accumulate with a lambda: acc + cell.getNumericValue().

std::string display() const — Returns the formatted table as a string representation for output.
Constraints
Row and column indices are 1-based (starting from 1).
Only numeric cells (INT and DOUBLE) are included in the average calculation.
If the specified range contains any STRING cell, average() must immediately return 0.0.
Output numeric values with 1 decimal place using std::fixed and std::setprecision(1).
Submission Files
Cell.cpp
Excel.cpp
Input/Output Example
Input (Table Data & Operation)	Expected Output
1
            
Name    C++     Java
Kim     87      75.7
Lee     90      80.6
Park    70      90.0
C++ Avg. Score: 82.3
Java Avg. Score: 82.1
            
2
            
Student Math    Physics
Alice   92      88.5
Bob     78      90.0
Charlie 85      85.5
Math Avg. Score: 85.0
Physics Avg. Score: 88.0
            
3
            
Item    Price
Pen     1.5
Notebook        2.8
Eraser  0.8
Average Price: 1.7
            