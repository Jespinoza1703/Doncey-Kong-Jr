#Referencias: fracek/CMakeLists.txt en github

cmake_minimum_required(VERSION 3.13)
project(Doncey_Kong_Jr C)

set(CMAKE_C_STANDARD 99)


add_executable(Doncey_Kong_Jr main.c
        entities/players/Monkey.c
        entities/enemies/BlueCrocodile.c)


# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})


target_link_libraries(Doncey_Kong_Jr ${GTK3_LIBRARIES})