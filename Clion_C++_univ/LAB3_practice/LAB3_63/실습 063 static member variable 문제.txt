실습 063 static member variable
Requested files: main.cpp, Logger.h, Logger.cpp (다운로드)
제출 방식: 개인
Goal
This exercise aims to help students understand and practice the use of static member variables and static member functions in C++17.

You will build a simple logging utility called Logger, which conditionally prints log messages depending on the configured log level. This helps students learn the fundamentals of static class members, a concept commonly used in system-level and utility classes.

Concept Explanation
In software development, a log is a message printed by a program to record information such as debugging data, warnings, or errors during execution.

In C++, static member variables belong to the class itself, not to any particular instance. This makes them ideal for sharing common state or configuration across the entire program.

Static member functions can be called without creating an object of the class. This is useful for utility functions like logging, which should be accessible globally.

In this problem, we will:

Define a static member variable to hold the current log level setting.
Define static member functions to log messages of different severity levels (DEBUG, INFO, WARNING, ERROR).
Only print a log message if its level is equal to or higher than the current log level.
The output format must follow: [LEVEL][TAG] message. For example: [INFO][main] This is an info message.

Classes or Functions to Implement
Enum

enum LogLevel { DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3 };
Logger Class

Logger.h
static int logLevel; - Static member variable to store the current logging level (initially INFO).
static void setLogLevel(LogLevel level); - Sets the current logging level.
static void debug(const std::string& message, const std::string& tag); - Prints a DEBUG message if log level allows.
static void info(const std::string& message, const std::string& tag); - Prints an INFO message if log level allows.
static void warning(const std::string& message, const std::string& tag); - Prints a WARNING message if log level allows.
static void error(const std::string& message, const std::string& tag); - Prints an ERROR message if log level allows.
Logger.cpp
Define logLevel outside the class with int Logger::logLevel = 1; (INFO by default).
Each log function should use std::cout to print messages in the format [LEVEL][TAG] message if the log level is equal to or higher than the current setting.
For example, if logLevel = INFO, then DEBUG messages should not be printed, but INFO, WARNING, and ERROR should.
Constraints
All member functions of Logger must be static.
The log level must be a class-wide shared configuration, implemented using a static member variable.
Messages must be printed only if their severity level is greater than or equal to the current log level.
Log message format must strictly follow: [LEVEL][TAG] message
Use std::cout for all output. Do not use external libraries.
Submission Files
Logger.cpp
Input/Output Example
Example 1
Input:

0
Output:

[DEBUG][main] This is a debug message
[INFO][main] This is an info message
[WARNING][main] This is a warning message
[ERROR][main] This is an error message
Example 2
Input:

1
Output:

[INFO][main] This is an info message
[WARNING][main] This is a warning message
[ERROR][main] This is an error message
Example 3
Input:

2
Output:

[WARNING][main] This is a warning message
[ERROR][main] This is an error message
Example 4
Input:

3
Output:

[ERROR][main] This is an error message
Example 5 (Invalid input defaults to DEBUG)
Input:

100
Output:

[DEBUG][main] This is a debug message
[INFO][main] This is an info message
[WARNING][main] This is a warning message
[ERROR][main] This is an error message