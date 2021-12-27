cmake_minimum_required(VERSION 3.19)
project(lab_2)


add_subdirectory(lib)
include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)

add_executable(lab_2 tests/test1.cpp main.cpp tests/uint.h uint1024_t.cpp uint1024_t.h)
target_link_libraries(lab_2 gtest gtest_main)