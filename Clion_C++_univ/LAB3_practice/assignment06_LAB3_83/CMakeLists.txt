cmake_minimum_required(VERSION 3.31)
project(assignment06)
set(CMAKE\_C\_FLAGS "\-fexec-charset=CP949")

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment06_LAB3_83
        String.cpp
        main.cpp)

target_include_directories(assignment06_LAB3_83 PRIVATE .)