//
// Created by jessica on 16/09/19.
//

#include "SDL.h"
#include <stdio.h>
#include "status.h"


void runGame(){
    Controller controller;
    SDL_Window *window = NULL;

    start(window, &controller);
    loadSurfaces(&controller);
    int done = 0;

    while(!done){
        done = eventProcessing(window, &controller);
        gameRendering(&controller);
        SDL_Delay(10);
    }
    closeWindow(window, &controller);
}