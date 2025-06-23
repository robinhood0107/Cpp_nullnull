cmake_minimum_required(VERSION 4.0)
project(LAB_92)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_92 DeviceTest.cpp
        LCD_Monitor.h
        LED_Monitor.h
        Monitor.h
        OutputDevice.h
        Printer.h)

target_include_directories(LAB_92 PRIVATE .)