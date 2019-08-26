cmake_minimum_required (VERSION 3.8)

project (config)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library (config INTERFACE)
target_include_directories (config INTERFACE include)

#add_subdirectory (sample/example_01_hello)

enable_testing ()
add_subdirectory (test)
