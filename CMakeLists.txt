cmake_minimum_required(VERSION 3.15)
project(FPMAX_LIB)
set(CMAKE_CXX_STANDARD 17)

set(
        src_files
        src/buffer.cpp
        src/data.cpp
        src/fp_node.cpp
        src/fp_tree.cpp
        src/fpmax.cpp
        src/fitemset.cpp
        src/fsout.cpp)

add_compile_options(-DMFI)

include_directories(src)

# Build Library
add_library(lib SHARED ${src_files})
set_target_properties(lib PROPERTIES OUTPUT_NAME fpmax)

# Test Library
include(CTest)
add_subdirectory(test/test-src/)
add_test(NAME       lib_test
         COMMAND    lib_test	${CMAKE_SOURCE_DIR}/test/test-data/transactions.txt)