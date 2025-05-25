cmake_minimum_required(VERSION 3.31)
project(64)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3_64
        main.cpp
        StringSplitter.cpp)

target_include_directories(LAB3_64 PRIVATE .)