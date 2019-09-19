#Referencias: fracek/CMakeLists.txt en github

cmake_minimum_required(VERSION 3.13)
project(Doncey_Kong_Jr C)

set(CMAKE_C_STANDARD 99)


add_executable(Doncey_Kong_Jr main.c
        src/entities/players/Monkey.c
        src/entities/enemies/BlueCrocodile.c
        src/graphics/Menu.c src/graphics/Menu.h src/entities/enemies/BlueCrocodile.h src/entities/players/Monkey.h)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


target_link_libraries(Doncey_Kong_Jr ${SDL2_LIBRARIES})