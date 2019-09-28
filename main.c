//
// Created by jessica on 16/09/19.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "src/game/Game.h"


int main(int argc, char *argv[]){

    Controller controller;
    SDL_Window *window = NULL;
    createWindow(window, &controller);
    //start();

    initializeGame(window, &controller, LIVESAMOUNT);
}