cmake_minimum_required(VERSION 4.0)
project(assignment08)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment08 main.cpp
        Department.cpp
        Department.hpp
        Employee.cpp
        Employee.hpp
        Manager.cpp
        Manager.hpp
        Organization.cpp
        Organization.hpp)

target_include_directories(assignment08 PRIVATE .)