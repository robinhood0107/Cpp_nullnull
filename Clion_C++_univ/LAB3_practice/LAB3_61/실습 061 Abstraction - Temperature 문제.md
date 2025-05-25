실습 061 Abstraction - Temperature
Requested files: TemperatureTest.cpp, Temperature.h, Temperature.cpp (다운로드)
제출 방식: 개인
Goal
This exercise is designed to help students practice abstracting real-world concepts into C++ objects. Students will implement a Temperature class that represents a temperature value in either Celsius or Fahrenheit.

Important: In this exercise, once a Temperature object is created, its internal state (temperature value and scale) must remain unchanged. When performing operations like addition, the function must return a new object instead of modifying the original ones. This principle teaches the students about object immutability and preserving object integrity, a fundamental aspect of object-oriented programming (OOP).

Concept Explanation
This problem strengthens the understanding of the following C++ concepts:

Object Immutability: Maintaining object state once initialized; functions should create and return new objects for state changes.

Enum Class: Using enum class for strong type-safe representations, preventing accidental misuse of plain enums.

Default Parameters: Using default arguments in the constructor instead of function overloading to provide flexibility while keeping the interface simple. (Hint: Specify default parameter values in the header file, not in the .cpp file.)

Encapsulation: Using private member variables and providing public member functions to interact with the object safely.

Classes or Functions to Implement
Enum Class: Scale (in Temperature.h)
Defines possible temperature scales:

Scale::Celsius
Scale::Fahrenheit
Class: Temperature (in Temperature.h and Temperature.cpp)
Private Member Variables:

double temperature; – The actual temperature value.
Scale scale; – The scale in which the temperature is measured.
Public Constructor:

Temperature(double temp, Scale scale = Scale::Celsius); – Initializes the temperature.
Tip: Set default parameters in the header file, not in the implementation file.

Public Member Functions:

Temperature add(const Temperature& other) const; – Returns a new Temperature object by adding the current temperature to another after appropriate scale conversion.

Tip: Since the object is immutable, this function must not modify *this or other; instead, it should create and return a new Temperature object.

std::string print() const; – Returns a formatted string with the temperature value rounded to one decimal place followed by 'C' or 'F'.

Tip: Use std::stringstream, std::fixed, and std::setprecision(1) for consistent formatting.

Private Helper Functions:

double toCelsius() const; – Converts the temperature to Celsius if it is not already.
double toFahrenheit() const; – Converts the temperature to Fahrenheit if it is not already.
Conversion Rules
When adding two temperatures with different scales, conversion is necessary. Use the following formulas:

Fahrenheit to Celsius:

To convert Fahrenheit to Celsius:

Celsius = (Fahrenheit - 32) × 5 ÷ 9
Celsius to Fahrenheit:

To convert Celsius to Fahrenheit:

Fahrenheit = (Celsius × 9 ÷ 5) + 32
These conversion formulas must be used in the toCelsius() and toFahrenheit() helper functions inside the Temperature class.

Helper Functions (in TemperatureTest.cpp)
Scale getScale(char scale); – Helper function to map character input ('C' or 'F') to Scale enum.
Temperature createTemperatureFromKeyboard(); – Reads a double and a character from standard input and creates a Temperature object accordingly.
Constraints
Temperature values are double precision floating-point numbers.
Input for scale should be a single uppercase character ('C' or 'F').
All printed outputs should be formatted to show one decimal place.
Class must follow the immutability rule: object state must not be changed after construction.
The result of addition must preserve the caller’s scale.
Submission Files
Temperature.cpp
Input/Output Example
입력	출력
25 C
77 F

25.0 C
77.0 F
50.0 C
154.0 F
117.8 C

50 F
20 C

50.0 F
20.0 C
118.0 F
30.0 C
204.0 F

77 F
50 F

77.0 F
50.0 F
127.0 F
127.0 F
254.0 F

25 C
20 C

25.0 C
20.0 C
45.0 C
45.0 C
90.0 C