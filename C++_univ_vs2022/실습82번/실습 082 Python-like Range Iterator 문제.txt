실습 082 Python-like Range Iterator
Requested files: main.cpp, Range.hpp, Range.cpp (다운로드)
제출 방식: 개인
Goal
In this problem, you will implement a custom class in C++ that mimics Python’s range() function. This will involve building an iterable object using a nested iterator class. The object should support iteration with different starting points, stopping points, and step values (both positive and negative), and be compatible with C++17 range-based for loops.

This problem offers hands-on practice with object-oriented programming, constructors, operator overloading, and iterator design, which are key elements in professional-grade C++ applications.

Concept Explanation
Why This Matters: Understanding how to build custom iterators helps students comprehend how the C++ STL works under the hood and prepares them to create iterable data structures of their own.

To complete this task, students need to understand the following concepts:

Class Construction: Defining multiple constructors to support various forms of initialization.

Nested Classes: Using a nested Iterator class within a Range class to encapsulate behavior.

Operator Overloading: Overloading *, ++, !=, and == to allow objects to be used in range-based for loops.

Custom Iterators: Creating STL-style iterators that support forward iteration logic, which is essential for compatibility with for ( : ) loops.

Edge Case Handling: Understanding when the range is logically empty and ensuring that the loop behaves correctly.

Clarification on Empty Ranges:

There are specific conditions under which the range is considered empty, and it is critical for your implementation to handle these correctly. If the following conditions are met, your range must be empty:

step == 0: Invalid step size, cannot proceed.

start == stop: The range contains no elements.

step > 0 and start > stop: Cannot reach stop from start in the positive direction.

step < 0 and start < stop: Cannot reach stop from start in the negative direction.

In all these cases, begin() and end() must return the same iterator, so that the range-based for loop does not enter the loop body.

Classes or Functions to Implement
Class: Range
Private Members:

long long start_: Starting value (inclusive)
long long stop_: Ending boundary (exclusive)
long long step_: Step value between each iteration
Constructors:

explicit Range(long long stop): Constructs a range from 0 to stop with step 1.
Range(long long start, long long stop): Constructs a range from start to stop with step 1.
Range(long long start, long long stop, long long step): Constructs a range from start to stop with custom step.
Member Functions:

Iterator begin() const: Returns an iterator to the beginning of the range.
Iterator end() const: Returns an iterator to the end of the range (one past the last valid element).
Nested Class: Range::Iterator
Purpose: Implements a forward iterator to support range-based iteration.

Private Members:

long long current_: Current value of iteration
long long step_: Step size per iteration
long long stop_: End value to determine termination
Constructor:

Iterator(long long current, long long step, long long stop)
Operator Overloads:

long long operator*() const: Returns current value
Iterator& operator++(): Advances to the next element (pre-increment)
Iterator operator++(int): Advances to the next element (post-increment)
bool operator!=(const Iterator& other) const:
Termination condition:

step > 0: return current_ < stop_
step < 0: return current_ > stop_
bool operator==(const Iterator& other) const: Logical negation of !=
Constraints
You may not use STL containers such as std::vector or std::list.

Ensure that step == 0 is treated as a special case resulting in an empty range.

For step > 0, the loop must terminate when current_ >= stop_.

For step < 0, the loop must terminate when current_ <= stop_.

Submission Files
Range.h: Header file for the Range and Iterator class declarations.
Range.cpp: Source file implementing the methods declared in Range.h.
Input/Output Example
range(5): 0 1 2 3 4 
range(2, 8): 2 3 4 5 6 7 
range(1, 10, 2): 1 3 5 7 9 
range(10, 0, -1): 10 9 8 7 6 5 4 3 2 1 
range(10, 0, -3): 10 7 4 1 
range(5, 5): 
range(10, 0, 1): 
range(0, 10, -1): 
range(1, 10, 0):