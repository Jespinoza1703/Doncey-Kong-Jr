//
// Created by atlas on 20/09/19.
//

#include "Util.h"

int collision(SDL_Rect recA, SDL_Rect recB){

    if(recA.x + recA.w <= recB.x)
        return 0;
    if(recA.x >= recB.x + recB.w)
        return 0;
    if(recA.y + recA.h <= recB.y)
        return 0;
    if(recA.y >= recB.y + recB.h)
        return 0;

    return 1;
}

int ledgeCollision(SDL_Rect recA, SDL_Rect recB){

    if(recA.y + recA.h <= recB.y)
        return 0;
    if(recA.y >= recB.y + recB.h)
        return 0;

    return 1;
}