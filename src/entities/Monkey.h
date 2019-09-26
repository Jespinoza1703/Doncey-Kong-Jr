//
// Created by jessica on 16/09/19.
//

#ifndef DONCEY_KONG_JR_MONKEY_H
#define DONCEY_KONG_JR_MONKEY_H

#include <stdio.h>
#include "../Util/GlobalVariables.h"

typedef struct
{
    float x, y;
    int width, height;
    int lives;
    float dx, dy;
    int onLedge, onRope;
    int isJumping;

    int animFrame, facingLeft, slowingDown;

} Monkey;


void moveRight(Monkey *monkey);
void moveLeft(Monkey *monkey);
void monkeyStill(Monkey *monkey);
void jump(Monkey *monkey, int time);
void animateMonkey(Monkey *monkey);



#endif //DONCEY_KONG_JR_MONKEY_H
