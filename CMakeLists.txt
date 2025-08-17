cmake_minimum_required(VERSION 3.1)

project(library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

option(BUILD_SHARED_LIBS "Build shared library" ON)

add_subdirectory(liblogger)
add_subdirectory(logger_app)