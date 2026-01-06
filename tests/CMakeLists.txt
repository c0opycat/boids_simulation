cmake_minimum_required(VERSION 4.0)
project(tests)

add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests_run gtest_main.cpp
        Vec2_tests.cpp
        DynamicArray_tests.cpp
        Boid_tests.cpp
        Settings_tests.cpp
        Utils_tests.cpp
        Flock_tests.cpp
        )

target_sources( tests_run PRIVATE
        ../src/Boid.cpp
        ../src/Settings.cpp
        ../src/utils/Utils.cpp
        ../src/Flock.cpp
        ../src/rules/AlignmentRule.cpp
        ../src/rules/CohesionRule.cpp
        ../src/rules/SeparationRule.cpp
        ../src/rules/TargetingRule.cpp
        )

target_link_libraries(tests_run gtest gtest_main)