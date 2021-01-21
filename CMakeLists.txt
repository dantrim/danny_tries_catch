cmake_minimum_required(VERSION 3.0.0)
project(danny_tries_catch VERSION 0.1.0)

##
## COMPILER CONFIGURATION
##
set(CMAKE_CXX_STANDARD 17)

###
### CATCH CONFIGURATION
###
#list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/Catch2/CMake)
#list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/Catch2/contrib)
#include(extern/Catch2/CMake/MiscFunctions.cmake) # needed for CheckFileLists
#
#add_definitions(-DCATCH_CONFIG_ENABLE_BENCHMARKING)
#option(CATCH_BUILD_EXAMPLES "Build Catch2's examples" OFF)
#option(CATCH_BUILD_TESTING "Enables building of Catch tests" OFF)
#include(Catch)

##
## PROJECT CONFIGURATION
##
#include(CTest)
#enable_testing()

add_subdirectory(extern/Catch2)
add_subdirectory(src)
add_subdirectory(tests)

##
## MISC
##
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)