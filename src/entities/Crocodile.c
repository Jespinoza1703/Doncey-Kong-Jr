//
// Created by jessica on 19/09/19.
//


#include "Crocodile.h"
#include "../structures/LinkedList.h"

void crocoMove(Crocodile *croco) {

    if (!croco->isRed) {

        if (croco->x < croco->rope->x){
            croco->x += CROCOSPEED;
        }
        else {
            croco->facingDown = 1;
            croco->y += CROCOSPEED;
        }
    }
}

void animateCroco(LinkedList *crocos){

    for (int i = 0; i < getSize(crocos); i++) {
        Crocodile *croco = (Crocodile *) getNode(crocos, i)->value;

        if(!croco->facingDown){

            if (croco->animFrame == 0) {
                croco->animFrame = 1;
            }else croco->animFrame = 0;
        }
        else{
            int width = croco->width;
            croco->width = croco->height;
            croco->height = width;
            if (croco->animFrame == 2) {
                croco->animFrame = 3;
            }else croco->animFrame = 2;
        }
    }
}