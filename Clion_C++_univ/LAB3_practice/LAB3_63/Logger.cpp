#include "Logger.h"
#include <iostream>

// Implememt your code
//기본적으로 static도 전부 다 Logger:: 이건 전부 붙인다. 이게 팁이다.

int Logger::logLevel = 1; //static
//반드시 주의할 점 => static도 무조건 Logger:: 이거 붙여야 함

std::string Logger::levelToString(LogLevel level) {
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



// 그리고 함수 static의 경우 앞에 static 붙일 이유가 없음


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

