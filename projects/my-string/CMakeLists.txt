add_library(my_string CMystring.cpp)
target_include_directories(my_string PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(my_string_demo main.cpp)
target_link_libraries(my_string_demo PRIVATE my_string)
