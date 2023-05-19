cmake_minimum_required(VERSION 3.24)
project(fourier_transform)

set(CMAKE_CXX_STANDARD 17)

add_executable(fourier_transform main.cpp
        include/fourier_transform.h
        include/log_duration.h
        include/test_framework.h
        include/tests.h
        include/utility_functions.h
        src/fourier_transform.cpp
        src/tests.cpp
        src/utility_functions.cpp
)
