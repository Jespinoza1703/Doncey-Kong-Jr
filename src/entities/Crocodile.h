//
// Created by jessica on 19/09/19.
//

#ifndef DONCEY_KONG_JR_CROCODILE_H
#define DONCEY_KONG_JR_CROCODILE_H

#include "../Util/GlobalVariables.h"
#include "Rope.h"
#include "../structures/LinkedList.h"

typedef struct
{
    float x, y;
    float dx, dy;
    int width, height;
    Rope *rope;
    int facingDown;

    int animFrame;
    int isRed;
    int speed;

} Crocodile;


void crocoMove(Crocodile *croco);
void animateCroco(LinkedList *crocos);


#endif //DONCEY_KONG_JR_CROCODILE_H
