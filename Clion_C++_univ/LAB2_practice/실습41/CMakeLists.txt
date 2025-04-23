cmake_minimum_required(VERSION 3.31)
project(41)

set(CMAKE_CXX_STANDARD 20)

add_executable(myprogram main.cpp input.cpp bmi.cpp)

target_include_directories(myprogram PRIVATE .)