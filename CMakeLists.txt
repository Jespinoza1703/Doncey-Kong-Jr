#Referencias: fracek/CMakeLists.txt en github

cmake_minimum_required(VERSION 3.13)
project(Doncey_Kong_Jr C)

set(CMAKE_C_STANDARD 99)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${PROJECT_SOURCE_DIR}/lib)


add_executable(Doncey_Kong_Jr main.c
        src/graphics/Menu.c
        src/graphics/Menu.h
        src/game/Game.c
        src/game/Game.h
        src/Util.c
        src/Util.h src/entities/Controller.c
        src/entities/Controller.h)


target_link_libraries(Doncey_Kong_Jr -lSDL2 -lSDL2_image)
