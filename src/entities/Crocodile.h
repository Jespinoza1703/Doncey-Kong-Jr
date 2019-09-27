//
// Created by jessica on 19/09/19.
//

#ifndef DONCEY_KONG_JR_CROCODILE_H
#define DONCEY_KONG_JR_CROCODILE_H

#include "../Util/GlobalVariables.h"
#include "../Util/Collisions.h"

typedef struct
{
    float x, y;
    float dx, dy;
    int width, height;
    int onRope;
    int facingUp, facingDown;

    int animFrame;
    int isRed;

} Crocodile;


void crocoMoveDown(Crocodile *croco);
void crocoMove(Crocodile *croco);
void animateCroco(Crocodile *croco);
int collideRope(Crocodile *croco);


#endif //DONCEY_KONG_JR_CROCODILE_H
