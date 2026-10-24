function(io_test name target input expected)
    add_test(NAME ${name} COMMAND "${CMAKE_COMMAND}"
        "-DPROGRAM=$<TARGET_FILE:${target}>"
        "-DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/${input}"
        "-DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/${expected}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/check-output.cmake")
endfunction()

include(cases.cmake)
add_executable(my_string_test my-string.cpp)
target_link_libraries(my_string_test PRIVATE my_string)
add_test(NAME my_string_value_semantics COMMAND my_string_test)
add_executable(tetris_test tetris.cpp ../coursework/assignments/tetris/stage05/tetris.cpp)
add_test(NAME tetris_game_actions COMMAND tetris_test)
