cmake_minimum_required(VERSION 3.0.0)
project(danny_tries_catch VERSION 0.1.0)

##
## COMPILER CONFIGURATION
##
set(CMAKE_CXX_STANDARD 17)

##
## SOURCE DIRECTORIES
##
add_subdirectory(extern/Catch2)
add_subdirectory(src)
add_subdirectory(tests)