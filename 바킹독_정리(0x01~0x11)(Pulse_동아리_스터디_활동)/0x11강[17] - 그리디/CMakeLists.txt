cmake_minimum_required(VERSION 3.31)
project(GREEDY)
set(CMAKE_CXX_STANDARD 20)
target_include_directories(GREEDY PRIVATE .)

add_compile_definitions(LOCAL_DEBUG)

add_executable(Out p11047.cpp)