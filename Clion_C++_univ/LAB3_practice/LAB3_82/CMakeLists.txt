cmake_minimum_required(VERSION 3.31)
project(82)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3_82
        main.cpp
        Range.cpp)

target_include_directories(LAB3_82 PRIVATE .)