cmake_minimum_required (VERSION 3.8)

project (tail)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library (tail INTERFACE)
target_include_directories (tail INTERFACE include)

add_subdirectory (examples)

enable_testing ()
add_subdirectory (tests)
