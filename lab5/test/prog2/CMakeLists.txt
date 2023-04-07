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

add_library(math1 SHARED ../../src/prog2/math1.cpp)
add_library(math2 SHARED ../../src/prog2/math2.cpp)

add_executable(prog2_test lab5_2test.cpp
                    ../../src/prog2/lab5_2.h
                    ../../src/prog2/lab5_2.cpp)

target_link_libraries(prog2_test PRIVATE math1 math2
                                        GTest::GTest)

target_include_directories(prog2_test PRIVATE)

add_test(prog2_test prog2)

project(tests)