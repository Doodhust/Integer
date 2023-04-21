cmake_minimum_required(VERSION 3.17)
project(Integer VERSION 1.0 LANGUAGES CXX)

add_compile_options(
        -Werror
        -Wall
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

include_directories(include)
include(GoogleTest)

add_library(IntegerLib STATIC src/Integer.cpp)
add_executable(IntegerTest test/integer_test.cpp)

target_link_libraries(IntegerTest PUBLIC IntegerLib GTest::gtest_main)