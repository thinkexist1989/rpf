cmake_minimum_required(VERSION 3.15)
project(rpf)

set(CMAKE_CXX_STANDARD 17)

add_library(rpf SHARED src/plugin_manager.cpp)
target_include_directories(rpf PUBLIC interfaces src)
