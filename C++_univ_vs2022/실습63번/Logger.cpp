#include "Logger.h"
#include <iostream>
#include <string>
// Implememt your code

int Logger::logLevel = 1;
//이게 제일 중요함
//static은 이게 무조건 필요함. 이거 무조건 외우고 있어라. C++만의 아주 독특한 문법


//private:
// Helper function to convert LogLevel to string representation
std::string Logger::levelToString(LogLevel level){
    switch(logLevel){
        case 0:
            return "DEBUG";
            break;
        case 2:
            return "WARNING";      
            break;
        case 3:
            return "ERROR";
            break;
        default:
            return "INFO";
            break;
    }
}


//public:
// Sets the current log level (static setter)
void Logger::setLogLevel(LogLevel level) {
    switch(level){
        case LogLevel::DEBUG:
            logLevel = 0;
            break;
        case LogLevel::WARNING:
            logLevel = 2;      
            break;
        case LogLevel::ERROR:
            logLevel = 3;    
            break;
        default:
            logLevel = 1;     
            break;
    }
}

// Logging methods (all static)
void Logger::debug(const std::string& message, const std::string& tag){
        logLevel=0;
        std::cout << '[' << Logger::levelToString(static_cast<LogLevel>(logLevel)) << ']' << '[' << tag << ']' << message << "\n";
}
void Logger::info(const std::string& message, const std::string& tag){
        logLevel=1;
        std::cout << '[' << Logger::levelToString(static_cast<LogLevel>(logLevel)) << ']' << '[' << tag << ']' << message << "\n";
}
void Logger::warning(const std::string& message, const std::string& tag){
        logLevel=2;
        std::cout << '[' << Logger::levelToString(static_cast<LogLevel>(logLevel)) << ']' << '[' << tag << ']' << message << "\n";
}
void Logger::error(const std::string& message, const std::string& tag){
        logLevel=3;
        std::cout << '[' << Logger::levelToString(static_cast<LogLevel>(logLevel)) << ']' << '[' << tag << ']' << message << "\n";
}