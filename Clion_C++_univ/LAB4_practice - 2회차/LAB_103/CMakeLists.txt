cmake_minimum_required(VERSION 4.0)
project(LAB_103)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_103 main.cpp
        my_make_unique.hpp
        Student.hpp)

target_include_directories(LAB_103 PRIVATE .)