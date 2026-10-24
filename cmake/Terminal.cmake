add_library(terminal INTERFACE)
if(WIN32)
    include(FetchContent)
    FetchContent_Declare(pdcurses
        URL https://codeload.github.com/wmcbrine/PDCurses/tar.gz/refs/tags/3.9
        URL_HASH SHA256=590dbe0f5835f66992df096d3602d0271103f90cf8557a5d124f693c2b40d7ec
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
    FetchContent_MakeAvailable(pdcurses)
    # 원본 소스를 고치지 않고 동일한 설정으로 정적 라이브러리를 빌드한다.
    file(GLOB pdc_core CONFIGURE_DEPENDS "${pdcurses_SOURCE_DIR}/pdcurses/*.c")
    file(GLOB pdc_win CONFIGURE_DEPENDS "${pdcurses_SOURCE_DIR}/wincon/*.c")
    add_library(pdcurses_win STATIC ${pdc_core} ${pdc_win})
    target_include_directories(pdcurses_win PUBLIC "${pdcurses_SOURCE_DIR}")
    target_compile_definitions(pdcurses_win PUBLIC PDC_WIDE PDC_FORCE_UTF8)
    target_link_libraries(pdcurses_win PUBLIC user32 advapi32)
    target_link_libraries(terminal INTERFACE pdcurses_win)
else()
    set(CURSES_NEED_WIDE TRUE)
    find_package(Curses REQUIRED)
    target_include_directories(terminal INTERFACE ${CURSES_INCLUDE_DIRS})
    target_link_libraries(terminal INTERFACE ${CURSES_LIBRARIES})
endif()
