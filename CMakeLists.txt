cmake_minimum_required(VERSION 3.12)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix Matrixtester.cpp matrix.cpp matrix.hpp)