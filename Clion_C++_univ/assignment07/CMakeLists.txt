cmake_minimum_required(VERSION 3.31)
project(assignment07)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment07
        main.cpp
        Matrix.cpp
        Matrix.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE )