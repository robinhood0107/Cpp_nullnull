
set(CURSES_LIBRARY "C:/msys64/mingw64/lib/libncurses.a")
set(CURSES_INCLUDE_PATH "C:/msys64/mingw64/include")
cmake_minimum_required(VERSION 3.30)
project(assignment03)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED COMPONENTS Libraries Includes) # COMPONENTS 추가

if(Curses_FOUND)
    include_directories(${Curses_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} main.cpp
            tetris.cpp
            tetris.h
            ui.cpp
            ui.h)
    target_link_libraries(${PROJECT_NAME} ${Curses_LIBRARIES})
else()
    message(FATAL_ERROR "ncurses library not found!")
endif()