cmake_minimum_required(VERSION 3.15)
project(FPMAX_LIB_Test)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(lib_test
        test.cpp
        ${CMAKE_SOURCE_DIR}/src/fpmax.h
        )

target_link_libraries(lib_test lib)  # need -lm to link math library

