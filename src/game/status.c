//
// Created by jessica on 16/09/19.
//

#include "SDL.h"
#include <stdio.h>
#include "status.h"


void runGame(){
    Game game;
    SDL_Window *window = NULL;

    initializeGame(window, &game);
    loadGraphics(&game);
    int done = 0;

    while(!done){
        done = processEvents(window, &game);
        gameRender(&game);
        SDL_Delay(10);
    }
    closeWindow(window, &game);
}