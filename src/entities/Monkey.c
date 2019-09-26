//
// Created by jessica on 16/09/19.
//

#include <math.h>
#include "Monkey.h"


void moveRight(Monkey *monkey){

    if(monkey->x < (SCREEN_WIDTH - monkey->width)){
        monkey->dx += 0.5;
        monkey->x += monkey->dx;
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

void moveLeft(Monkey *monkey){

    if(monkey->x > 0){
        monkey->dx -= 0.5;
        monkey->x += monkey->dx;
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



void jump(Monkey *monkey) {

    if (!monkey->isJumping) {
        if (monkey->dy < 100) {
            monkey->y -= SPEED*3;
            monkey->dy += SPEED;
            monkey->isJumping;
        }
    }else{
        monkey->y += GRAVITY;
        monkey->dy = 0;
    }

}


void animateMonkey(Monkey *monkey){

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

