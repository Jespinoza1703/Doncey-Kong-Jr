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
        src/game/Controller.c
        src/game/Controller.h src/structures/LinkedList.c src/structures/LinkedList.h src/structures/Node.c src/structures/Node.h src/entities/Monkey.c src/entities/Monkey.h src/entities/Ledge.c src/entities/Ledge.h src/Util/GlobalVariables.h src/entities/Rope.c src/entities/Rope.h src/Util/Collisions.c src/Util/Collisions.h src/entities/Crocodile.c src/entities/Crocodile.h src/entities/Fruit.c src/entities/Fruit.h)


target_link_libraries(Doncey_Kong_Jr -lSDL2 -lSDL2_image)
