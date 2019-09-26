//
// Created by jessica on 18/09/19.
//

#include "Collisions.h"

//Check for collision with any ledges (brick blocks)
void ledgeCollision(Monkey *monkey, Ledge **ledges)
{
    for(int i = 0; i < LEDGEAMOUNT; i++)
    {
        float ledgeX = ledges[i]->x, ledgeY = ledges[i]->y;
        float ledgeWidth = ledges[i]->width, ledgeHeight = ledges[i]->height;

        if(monkey->x + monkey->width/2 > ledgeX && monkey->x+monkey->width/2 < ledgeX + ledgeWidth)
        {
            //are we bumping our head?
            if(monkey->y < ledgeY + ledgeHeight && monkey->y > ledgeY && monkey->dy < 0)
            {
                //stop jump velocity
                monkey->dy = 0;
                monkey->onLedge = 1;

                //correct y
                monkey->y += SPEED;
            }
        }

        if(monkey->x + monkey->width > ledgeX && monkey->x < ledgeX + ledgeWidth)
        {
            //are we landing on the ledge
            if(monkey->y+monkey->height > ledgeY && monkey->y < ledgeY && monkey->dy > 0)
            {
                //correct y
                monkey->y = ledgeY - monkey->height;

                //landed on this ledge, stop any jump velocity
                monkey->dy = 0;
                monkey->onLedge = 1;
            }
        }
    }
}