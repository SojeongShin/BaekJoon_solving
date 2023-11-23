cmake_minimum_required(VERSION 3.26)
project(GradeSorting C)

set(CMAKE_C_STANDARD 11)

add_executable(GradeSorting main.c
        grade.c
)
