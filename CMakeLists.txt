cmake_minimum_required(VERSION 3.8)
project(ecosnail)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(cmake/project.cmake)

enable_testing()

add_subdirectory(projects)
