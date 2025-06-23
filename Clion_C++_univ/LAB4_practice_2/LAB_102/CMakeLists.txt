cmake_minimum_required(VERSION 4.0)
project(LAB_102)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_102 main.cpp
                my_vector.hpp)

target_include_directories(LAB_102 PRIVATE .)