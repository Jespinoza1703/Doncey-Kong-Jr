//
// Created by jessica on 17/09/19.
//

#include <stdlib.h>
#include "Ledge.h"


Ledge *newLedge(int x, int y, int width, int height){

    Ledge *ledge = (Ledge*) malloc(sizeof(Ledge));
    ledge->x = x;
    ledge->y = y;
    ledge->width = width;
    ledge->height = height;

    return ledge;
}