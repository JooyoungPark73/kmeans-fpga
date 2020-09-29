cmake_minimum_required(VERSION 3.16)
project(kmeans_fpga)

set(CMAKE_CXX_STANDARD 14)

add_executable(kmeans_fpga
        file_io.cpp
        main.cpp
        common.h
        kmeans.cpp
        kmeans_init.cpp)
