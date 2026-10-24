실습 103 my_make_unique
Requested files: main.cpp, Student.hpp, my_make_unique.hpp (다운로드)
제출 방식: 개인
Goal
Implement a function my_make_unique that mimics the behavior of std::make_unique using variadic templates and std::forward. You must also implement a Student class with multiple constructors to verify how different types and counts of parameters are handled using perfect forwarding.

Concept Explanation
1. Variadic Templates and Parameter Packs
Variadic templates allow you to define functions or classes that accept any number of arguments. A parameter pack (Args...) collects multiple arguments into a single bundle that you can later unpack and use.

Pack Expansion
Pack expansion is the most common way to unpack a parameter pack. Using the syntax pattern..., a pattern is applied to each element of the pack and expanded into a comma-separated list.

Examples of pack expansion:

function(args...) expands to function(arg1, arg2, arg3)
{args...} expands to {arg1, arg2, arg3}
std::forward<Args>(args)... expands to std::forward<T1>(arg1), std::forward<T2>(arg2), ...
Pack expansion is typically used in the context of function arguments, initializer lists, or fold expressions.

Example 1: Forwarding arguments to a constructor or another function
This example shows how to use pack expansion to forward a list of arguments to another function:

template<typename... Args>
void call_all(Args... args) {
    print_all(args...); // Pack expansion
}
Example 2: Using Fold Expressions in C++17
Fold expressions offer a compact way to apply a binary operator to all elements in a pack:

template<typename... Args>
int sum(Args... args) {
    return (args + ...); // Left fold
}
This expression expands into (arg1 + arg2 + arg3 + ...), simplifying the code and removing the need for recursion.

2. Forwarding References and std::forward
The purpose of forwarding references and std::forward is to implement perfect forwarding: forwarding arguments while preserving whether they were passed as lvalues or rvalues.

Forwarding References vs. R-value References
Type&& (rvalue reference): binds only to rvalues; used for move semantics.
T&& (forwarding reference): when T is a template parameter, this binds to both lvalues and rvalues.
The Need for std::forward
Inside a function, all named parameters are treated as lvalues—even if the original argument was an rvalue. std::forward is used to cast the parameter back to its original category so that the correct constructor or overload is called.

Incorrect Proxy Example (No Forwarding)
template<typename T>
void proxy(T&& val) {
    some_function(val); // Always passed as lvalue
}
Correct Proxy Example Using std::forward
template<typename T>
void proxy(T&& val) {
    some_function(std::forward<T>(val)); // Perfectly forwards lvalue or rvalue
}
Case	Role	Location (Context)
1. typename... Args	Template Parameter Pack Declaration	Inside template<...>
2. Args&&... args	Function Parameter Pack Declaration	In function parameters (...)
3. pack...	General Pack Expansion	Function calls, initializers, etc.
4. Fold Expression	Fold Expression	Inside () with an operator, applied to all elements of a parameter pack (e.g., Unary: (pack op ...), Binary: (init op ... op pack)).
Classes or Functions to Implement
1. Class Student

std::string name: stores the student's name
int year: stores the academic year
Student(): default constructor
Student(const std::string&): constructor accepting only a name (lvalue)
Student(std::string&&): constructor accepting an rvalue name
Student(const std::string&, int): constructor accepting name and year
Student(std::string&&, int): constructor accepting rvalue name and year
friend std::ostream& operator<<(std::ostream&, const Student&): overload output to print the name and year
2. Function Template my_make_unique

Signature: template<typename T, typename... Args> std::unique_ptr<T> my_make_unique(Args&&... args);
Functionality: Constructs and returns a std::unique_ptr<T> using the arguments forwarded to the constructor of T
Constraints
Use C++17 standard
Do not use std::make_unique
Use std::forward to preserve the value category of forwarded arguments
Submission Files
Student.hpp: Defines the Student class and operator overload
my_make_unique.hpp: Implements my_make_unique
Input/Output Example
Kim 4
Lee 4
Choi 1