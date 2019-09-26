//
// Created by jessica on 19/09/19.
//

#ifndef DONCEY_KONG_JR_CROCODILE_H
#define DONCEY_KONG_JR_CROCODILE_H


typedef struct
{
    float x, y;
    int width, height;
    int onRope;
    int facingRight, facingDown;

    int animFrame

} Crocodile;


void moveRight(Crocodile *croco);
void moveDown(Crocodile *croco);
void animateCroco(Crocodile *croco);


#endif //DONCEY_KONG_JR_CROCODILE_H
