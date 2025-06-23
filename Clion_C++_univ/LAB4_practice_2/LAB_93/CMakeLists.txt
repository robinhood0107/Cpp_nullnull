cmake_minimum_required(VERSION 4.0)
project(LAB_93)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_93 main.cpp
        Vehicle.cpp
        Vehicle.hpp)

target_include_directories(LAB_93 PRIVATE .)