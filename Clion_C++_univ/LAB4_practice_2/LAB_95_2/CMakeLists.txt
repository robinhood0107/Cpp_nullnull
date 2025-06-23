cmake_minimum_required(VERSION 4.0)
project(LAB_95_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_95_2 main.cpp
        Skill.hpp
        Champion.hpp)

target_include_directories(LAB_95_2 PRIVATE .)