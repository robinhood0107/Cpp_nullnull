실습 112 - File I/O Exception Handling
Requested files: main.cpp (다운로드)
업로드 가능한 파일 수: 2
제출 방식: 개인
Goal
Write a C++17 program that demonstrates robust file input and output using ifstream and ofstream, with proper exception handling. This exercise aims to help students deliberately trigger exceptions using invalid file paths and handle them using ios::failure.

Concept Explanation
File I/O in C++ is accomplished through stream-based interfaces: ifstream for reading and ofstream for writing. However, these streams do not throw exceptions by default. Instead, they set error flags like failbit (recoverable errors like file not found) or badbit (unrecoverable stream errors).

To explicitly detect and handle these errors, exception masks can be set using exceptions(failbit | badbit). Once enabled, any operation that sets these flags will throw an ios::failure exception.

Key Concepts:

failbit: Indicates a logical error on input/output operation (e.g., trying to open a file that doesn't exist).
badbit: Indicates a read/write error on the stream, often due to hardware or OS-level problems.
ios::failure: Exception type thrown when one of the above bits is set and exceptions are enabled.
RAII (Resource Acquisition Is Initialization): File streams are closed automatically when going out of scope. No need to call close() explicitly.
Triggering Exceptions with ofstream: The line below is included in the code to intentionally cause an exception:

ofstream fout;
fout.open("config/config.ini");
This line attempts to write to a file inside the config/ directory. However, if the config/ directory does not exist (as expected in this exercise), fout.open() fails and throws an exception if failbit or badbit is enabled.

Note: ofstream will automatically create a file if it doesn’t exist, but it does not create directories. Therefore, attempting to write to a nested path with a non-existent directory is a common and deliberate way to trigger an exception in this context.

Classes or Functions to Implement
This task only requires implementation in the main function:

Declare both ifstream and ofstream.
Configure them to throw exceptions on failbit and badbit.
Attempt to open non-existent files to trigger exceptions.
Catch ios::failure exceptions using const reference and output the error with e.what().
Constraints
Only catch ios::failure exceptions.
Do not manually create the "config" directory. This absence is intentional to cause a write error.
Use separate try-catch blocks for reading and writing.
No input is required.
RAII should be applied — do not call close() manually.
Submission Files
main.cpp: Contains the main function and exception-handling logic.
Input/Output Example
basic_ios::clear: iostream error