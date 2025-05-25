cmake_minimum_required(VERSION 3.31)
project(63)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3_63
        Logger.cpp
        main.cpp)

target_include_directories(LAB3_63 PRIVATE .)