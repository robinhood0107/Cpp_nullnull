cmake_minimum_required(VERSION 3.27)
project(CppHW2)

set(CMAKE_CXX_STANDARD 17)

set(CURSES_INCLUDE_PATH "C:/msys64/mingw64/include")
set(CURSES_LIBRARY "C:/msys64/mingw64/lib/libncurses.dll.a")

include_directories(${CURSES_INCLUDE_PATH})
add_executable(CppHW2 ui.cpp)
target_link_libraries(CppHW2 ${CURSES_LIBRARY} ncursesw)