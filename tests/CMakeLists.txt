##
## CATCH CONFIGURATION
##
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/Catch2/CMake)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/Catch2/contrib)
include(${PROJECT_SOURCE_DIR}/extern/Catch2/CMake/MiscFunctions.cmake) # needed for CheckFileLists

add_definitions(-DCATCH_CONFIG_ENABLE_BENCHMARKING)
option(CATCH_BUILD_EXAMPLES "Build Catch2's examples" OFF)
option(CATCH_BUILD_TESTING "Enables building of Catch tests" OFF)
option(CATCH_INSTALL_HELPERS ON)
include(CTest)
include(Catch)
enable_testing()

##
## LIBRARY INCLUDES
##
include_directories(${PROJECT_SOURCE_DIR}/src)

##
## All tests are grouped together
##
add_executable(tests_main tests_main.cpp)
target_link_libraries(tests_main PRIVATE foo Catch2::Catch2)
catch_discover_tests(tests_main)