실습 111 - out_of_range exception
Requested files: main.cpp, Array.hpp (다운로드)
제출 방식: 개인
Goal
Write a C++17 program that defines a safe array access class using templates and handles out-of-bounds access with exception handling using try, catch, and throw.

Concept Explanation
In C++, arrays are stored in a contiguous block of memory, and elements are accessed using indices starting from 0 up to n - 1, where n is the size of the array.

For example, if we have Array arr(5);, valid indices are 0, 1, 2, 3, and 4. Accessing arr.at(5) or arr.at(-1) is invalid and should be considered an out-of-bounds access.

In languages like Java, such situations throw an ArrayIndexOutOfBoundsException. In C++, to build robust programs, we can manually detect out-of-bounds accesses and handle them using exception mechanisms.

The goal of this exercise is to implement a custom generic Array class using templates. The class should throw a std::out_of_range exception when an invalid index is accessed using the at() method. In the main() function, students will write code to catch this exception and print an error message.

Classes or Functions to Implement
Array.hpp

template<typename T> class Array: A generic array class with bounds checking.
Array(size_t size): Constructor that allocates memory for the array.
T& at(size_t index): Member function that throws std::out_of_range if the index is out of bounds.
~Array(): Destructor to release allocated memory.
main.cpp

main(): Instantiate an Array, assign values, access an invalid index to trigger an exception, and catch and handle the exception using a try-catch block.
Constraints
Only the std::out_of_range exception needs to be handled.
Memory allocation is assumed to succeed, and no other exceptions need to be considered.
Submission Files
Array.hpp
main.cpp
Input/Output Example
Out of Range error: 5