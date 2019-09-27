//
// Created by jessica on 19/09/19.
//


#include "Crocodile.h"


void crocoMoveDown(Crocodile *croco){

    croco->x = croco->dx;
    if(!croco->isRed){
        croco->y += CROCOSPEED;
    }
    else{
        croco->y += CROCOSPEED;
        croco->dy = croco->y;
    }
}

void crocoMove(Crocodile *croco){

    croco->x += CROCOSPEED;
    croco->dx = croco->x;
    /*
    if(collideRope(croco)){
        croco->facingDown = 1;
        crocoMoveDown(croco);
    }
     */
}

void animateCroco(Crocodile *croco){

}