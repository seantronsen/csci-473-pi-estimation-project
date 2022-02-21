cmake_minimum_required(VERSION 3.21)
project(pi_project C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -lm")
add_executable("${PROJECT_NAME}" pi_parallel.c)
target_link_libraries("${PROJECT_NAME}" m)
