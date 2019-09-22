//
// Created by jessica on 16/09/19.
//

#include "SDL.h"
#include <stdio.h>
#include "status.h"


void runGame(){

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