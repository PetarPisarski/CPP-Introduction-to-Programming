cmake_minimum_required(VERSION 3.10)

project(PerfectNumbers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PerfectNumbers
        main.cpp
        functions.cpp
)

target_compile_options(PerfectNumbers PRIVATE -Wall -Wextra -pedantic)