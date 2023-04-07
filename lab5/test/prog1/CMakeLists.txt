cmake_minimum_required(VERSION 3.16.3)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


set(CMAKE_CXX_STANDARD 17)


# LAB 5 tests

add_executable(prog1_test lab5_1test.cpp
                    ../../src/prog1/lab5_1.cpp
                    ../../src/prog1/lab5_1.h
                    ../../src/prog1/math1.cpp
                    ../../src/prog1/math1.h )

target_link_libraries(prog1_test PRIVATE GTest::GTest)
target_include_directories(prog1_test PRIVATE)

add_test(prog1_test prog1_test)

project(tests)