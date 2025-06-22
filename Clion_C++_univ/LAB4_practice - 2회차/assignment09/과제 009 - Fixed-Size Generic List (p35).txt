과제 009 - Fixed-Size Generic List (p35)
Requested files: main.cpp, MyList.hpp (다운로드)
제출 방식: 개인
Goal
Write a generic container class MyList using C++ templates that mimics a fixed-size dynamic array. This practice will help students understand how template classes work, how dynamic memory is managed manually, and how to implement basic class features like constructors, destructors, and operator overloading.

Concept Explanation
Templates in C++ allow writing code that works with any data type. For example, you can create a list that stores integers, strings, or even complex numbers using the same class definition. This feature is useful in developing generic libraries like STL.

A common challenge with templates is implementation: template functions must be implemented in header files because template classes are instantiated during compilation, and the compiler must see the full definition when it generates code for specific types.

In this problem, students will implement a class template MyList<T, N> that:

Supports adding and removing elements.
Implements deep copy through a copy constructor and copy assignment operator.
Manages memory safely using dynamic arrays.
Provides begin/end iterators for use with STL algorithms like std::find.
Classes or Functions to Implement
Class: MyList<T, N>

Variables:
T* _data: Pointer to the array of type T.
int pos: Index to track the number of elements stored.
Functions:
MyList(): Constructor that allocates dynamic memory.
~MyList() noexcept: Destructor that deallocates memory.
MyList(const MyList& rhs) noexcept: Copy constructor (deep copy).
MyList& operator=(const MyList& rhs): Copy assignment operator.
void add(T& data): Adds an element to the list if space permits.
void remove(T& data): Removes an element if it exists and shifts remaining items.
T* begin() and const T* begin() const: Iterator to the first element.
T* end() and const T* end() const: Iterator to the element after the last valid element (use pos).
Constraints

Use only standard C++17 (no external libraries except <complex>, <vector>, and <algorithm>).
Maximum list size is defined by template parameter N.
Ensure deep copy semantics to prevent memory bugs.
Submission Files

MyList.h
Input/Output Example
Found: (0,0)
Found: abc
(1,1)
(2,2)
def
ghi
def
ghi
def
ghi
abc
ghi
abc
def
ghi
abc