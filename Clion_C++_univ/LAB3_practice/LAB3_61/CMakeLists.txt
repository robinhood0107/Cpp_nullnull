cmake_minimum_required(VERSION 3.31)
project(61)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB3_61 Temperature.cpp TemperatureTest.cpp)

target_include_directories(LAB3_61 PRIVATE .)