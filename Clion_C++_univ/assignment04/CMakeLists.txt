cmake_minimum_required(VERSION 3.30)
project(assignment04)

set(CMAKE_CXX_STANDARD 17)

# Set paths manually
find_library(NCURSES_LIBRARY ncursesw HINTS ENV PATH PATHS /mingw64/lib)
include_directories("C:/msys64/mingw64/include")
link_libraries("C:/msys64/mingw64/lib/libncurses.a")

add_executable(${PROJECT_NAME}
        main.cpp
        tetris.cpp
        tetris.h
        ui.cpp
        ui.h
)
target_link_libraries(assignment04 PRIVATE ncursesw)