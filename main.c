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

    loadGraphics(&controller);

    //Enter loop
    int finish = 0;

    //Event loop
    while(finish != 1)
    {
        finish = eventManager(window, &controller);

        //Render
        render(&controller);
        move(&controller);
        collisionDetect(&controller);

        SDL_Delay(10);
    }

    closeWindow(window, &controller);
}