cmake_minimum_required(VERSION 3.13)
project(Doncey_Kong_Jr C)

set(CMAKE_C_STANDARD 99)

add_executable(Doncey_Kong_Jr main.c
        entities/players/Monkey.c
        entities/enemies/BlueCrocodile.c)