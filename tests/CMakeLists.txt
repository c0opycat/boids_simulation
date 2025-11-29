cmake_minimum_required(VERSION 4.0)
project(tests)

add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests_run gtest_main.cpp Vec2_tests.cpp)
target_link_libraries(tests_run gtest gtest_main)