//
// Created by jessica on 16/09/19.
//

#include <math.h>
#include "Monkey.h"


void moveRight(Monkey *monkey){

    if(monkey->x > 0){
        monkey->dx -= 0.25;
        if(monkey->dx < -SPEED)
        {
            monkey->dx = -SPEED;
        }
        monkey->facingLeft = 1;
        monkey->slowingDown = 0;
    }
    else{
        monkey->x = 0;
    }
}

void moveLeft(Monkey *monkey){

    if(monkey->x < (SCREEN_WIDTH - monkey->width)){
        monkey->dx += 0.25;
        if(monkey->dx > SPEED)
        {
            monkey->dx = SPEED;
        }
        monkey->facingLeft = 0;
        monkey->slowingDown = 0;
    }
    else{
        monkey->x = (SCREEN_WIDTH - monkey->width);
    }
}

void jump(Monkey *monkey){

    monkey->dy -= 0.2f;
    monkey->animFrame = 4;
}

void animateMonkey(Monkey *monkey){

    monkey->x += monkey->dx;
    monkey->y += monkey->dy;

    if(monkey->dx != 0 && monkey->onLedge && !monkey->slowingDown)
    {

        if(monkey->animFrame < 4)
        {
            monkey->animFrame++;
        }
        else {
            monkey->animFrame = 1;
        }
    }
    monkey->dy += GRAVITY;
}

void monkeyStill(Monkey *monkey) {

    if (monkey->y < (SCREEN_HEIGHT)) {
        monkey->animFrame = 0;
        monkey->dx *= 0.5f;
        monkey->slowingDown = 1;
        if (fabsf(monkey->dx) < 0.1f) {
            monkey->dx = 0;
        }
    }
}

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