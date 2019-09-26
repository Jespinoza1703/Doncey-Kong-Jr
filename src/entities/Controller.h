//
// Created by atlas on 22/09/19.
//

#ifndef DONCEY_KONG_JR_CONTROLLER_H
#define DONCEY_KONG_JR_CONTROLLER_H

#include "SDL.h"
#include "SDL_image.h"
#include "Monkey.h"
#include "Ledge.h"
#include "../Util/GlobalVariables.h"
#include "Rope.h"



typedef struct
{

    //Images
    SDL_Texture *monkeyFrames[5];
    SDL_Texture *livesFrames[4];
    SDL_Texture *ropeFrames[ROPEAMOUNT];
    SDL_Texture *blueCrocoFrames[5];
    SDL_Texture *redCrocoFrames[5];
    SDL_Texture *banana_img;
    SDL_Texture *mango_img;
    SDL_Texture *apple_img;
    SDL_Texture *ledge_img;
    SDL_Texture *donkeyK_img;

    int time;

    //Renderer
    SDL_Renderer *renderer;

    int end;

} Controller;


void loadGraphics(Controller *controller);
void closeWindow(SDL_Window *window, Controller *controller);


#endif //DONCEY_KONG_JR_CONTROLLER_H

