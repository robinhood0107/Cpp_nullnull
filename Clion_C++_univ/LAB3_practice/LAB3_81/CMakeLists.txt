cmake_minimum_required(VERSION 3.31)
project(81)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3_81
        main.cpp
        Complex.cpp)

target_include_directories(LAB3_81 PRIVATE .)