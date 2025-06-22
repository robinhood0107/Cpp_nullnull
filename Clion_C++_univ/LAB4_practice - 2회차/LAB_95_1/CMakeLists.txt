cmake_minimum_required(VERSION 4.0)
project(LAB_95_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_95_1
        Employee.h
        EmployeeTest.cpp)

target_include_directories(LAB_95_1 PRIVATE .)