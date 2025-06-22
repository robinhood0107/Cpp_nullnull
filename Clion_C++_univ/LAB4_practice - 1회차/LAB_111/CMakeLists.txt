cmake_minimum_required(VERSION 4.0)
project(LAB_111)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_111 main.cpp
        Array.hpp)

target_include_directories(LAB_111 PRIVATE .)