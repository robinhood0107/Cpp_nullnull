cmake_minimum_required(VERSION 4.0)
project(assignment09)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment09 main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE .)