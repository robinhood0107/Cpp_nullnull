cmake_minimum_required(VERSION 3.31)
project(Test)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test
        main.cpp
        Matrix.cpp
        Matrix.hpp)

target_include_directories(Test PRIVATE .)