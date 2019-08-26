cmake_minimum_required (VERSION 3.8)

project (dimentia)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library (dimentia INTERFACE)
target_include_directories (dimentia INTERFACE include)

target_link_libraries (dimentia INTERFACE tail)

if (NOT TARGET tail)
    add_subdirectory (deps/tail)
endif ()

add_subdirectory (examples)

enable_testing ()
add_subdirectory (tests)
