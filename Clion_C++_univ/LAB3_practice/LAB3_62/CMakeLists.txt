cmake_minimum_required(VERSION 3.31)
project(62)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3_62
        test_Excel.cpp
        Excel.cpp
        Cell.cpp)

target_include_directories(LAB3_62 PRIVATE .)