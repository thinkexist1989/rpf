cmake_minimum_required(VERSION 3.15)
project(rpf)

set(CMAKE_CXX_STANDARD 17)

add_library(rpf SHARED library.cpp
        interfaces/plugin_base.hpp)
