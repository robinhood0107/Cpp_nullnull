과제 006 - My String 클래스
Requested files: main.cpp, String.h, String.cpp (다운로드)
제출 방식: 개인
Goal
The goal of this assignment is to implement a basic version of a custom String class using C++17, focusing on class construction and memory management fundamentals. You will implement essential special member functions (default constructor, parameterized constructor, copy constructor, destructor) and utility member functions such as empty(), size(), and append(). You must ensure deep copying and proper memory management using raw pointers. Additionally, students will practice using the C++ Standard Library functions (e.g., std::copy) to work with C-style strings.

Concept Explanation
To complete this task, you should understand the following core concepts:

1. C-style Strings: These are arrays of characters ending in a null terminator ('\0'). You will handle memory manually (with new and delete) for such strings.

2. Dynamic Memory Management: The String class uses a char* pointer, which means you are responsible for allocating and deallocating memory. Use new for allocation and delete[] for deallocation.

3. Special Member Functions: You must implement the following special member functions to manage resources safely:

Default Constructor: Initializes an empty string.
Parameterized Constructor: Initializes from a C-style string.
Copy Constructor: Implements deep copy of string data.
Destructor: Properly deallocates memory.
4. Utility Functions: These include:

empty(): Checks if the string is empty.
size(): Returns the length of the string.
append(): Appends another String or const char* to the current string.
5. Use of STL Algorithms: You are encouraged to use std::copy from <algorithm> to help copy characters from one array to another.

6. Static Member Variable: count_ tracks the number of active String objects. It should be incremented in constructors and decremented in the destructor. Use this to output the current object count as shown in the expected outputs.

Classes or Functions to Implement
Class: String

String(): Default constructor that initializes an empty string (empty string with length 0 and data as a null-terminated string).
explicit String(const char* s): Constructor that initializes string data by copying content from C-style string s. If s == nullptr, treat it as empty string.
String(const String& s): Copy constructor that performs a deep copy of s's data.
~String() noexcept: Destructor that deallocates dynamic memory.
bool empty() const: Returns true if the string is empty.
size_t size() const: Returns the length of the string (not including null terminator).
String& append(const String& str): Appends content of another String object to the current object.
String& append(const char* str): Appends content from C-style string str to the current object.
const char* data() const: Returns a const pointer to the string data.
Static Members:

static int count_: Keeps track of the number of String objects. Increase in constructors and decrease in destructor.
Constraints
Implement all required functions only in String.cpp.
Use deep copy wherever applicable. Avoid shallow copying of string data.
Use std::copy where appropriate when copying strings.
Ensure null-termination of internal strings.
append() must handle empty strings correctly.
Note: In all constructors and destructor, you should output messages such as Constructor, Copy Constructor, Destructor, and the current object count like this:

std::cout << "Constructor" << std::endl; 
std::cout << "# of String object: " << count_ << std::endl; 
Submission Files
String.cpp: Implement all logic here.
Input/Output Example
Input:

(No input file. Logic is tested through predefined test cases in main.cpp)

Output:

Note: This output will be automatically generated if your implementation is correct. Carefully compare the object count and constructor/destructor messages to verify memory management.

 
Testing the default constructor: 

Default Constructor
# of String object: 1
Destructor
# of String object: 0


Testing the constructor that takes a C-style string:

Constructor
# of String object: 1
Constructor
# of String object: 2
Destructor
# of String object: 1
Destructor
# of String object: 0


Testing the copy constructor:

Constructor
# of String object: 1
Copy Constructor
# of String object: 2
Constructor
# of String object: 3
Copy Constructor
# of String object: 4
Destructor
# of String object: 3
Destructor
# of String object: 2
Destructor
# of String object: 1
Destructor
# of String object: 0


Testing the append() function:

Constructor
# of String object: 1
Constructor
# of String object: 2
Constructor
# of String object: 3
Constructor
# of String object: 4
Destructor
# of String object: 3
Destructor
# of String object: 2
Destructor
# of String object: 1
Destructor
# of String object: 0