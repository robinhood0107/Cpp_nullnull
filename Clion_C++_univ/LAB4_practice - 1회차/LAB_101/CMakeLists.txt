cmake_minimum_required(VERSION 4.0)
project(LAB_101)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_101 main.cpp
        my_accumulate.hpp)

target_include_directories(LAB_101 PRIVATE .)