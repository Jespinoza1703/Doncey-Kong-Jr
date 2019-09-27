//
// Created by Jesica on 18/09/19.
//

#ifndef DONCEY_KONG_JR_CONTROLLER_H
#define DONCEY_KONG_JR_CONTROLLER_H

#include "SDL.h"
#include "SDL_image.h"
#include "../Util/GlobalVariables.h"
#include "../structures/LinkedList.h"
#include "Ledge.h"
#include "Rope.h"


typedef struct
{
    //Images
    SDL_Texture *monkeyFrames[MONKEYFRAMES];
    SDL_Texture *livesFrames[4];
    SDL_Texture *ropeFrames[ROPEAMOUNT];
    SDL_Texture *blueCrocoFrames[BLUECROCOFRAMES];
    SDL_Texture *redCrocoFrames[REDCROCOFRAMES];
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
void renderLedges(Controller *controller, Ledge **ledges);
void renderRopes(Controller *controller, Rope **ropes);
void renderLives(Controller *controller);
void renderDonkey(Controller *controller);
void renderCrocos(Controller *controller, LinkedList *crocos);
void closeWindow(SDL_Window *window, Controller *controller);


#endif //DONCEY_KONG_JR_CONTROLLER_H

