cmake_minimum_required (VERSION 3.8)

project (evening)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library (evening INTERFACE)
target_include_directories (evening INTERFACE include)

enable_testing ()
add_subdirectory (tests)
