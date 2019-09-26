//
// Created by jessica on 17/09/19.
//

#include "Rope.h"
#include <stdlib.h>

Rope *newRope(int x, int y, int width, int height){

    Rope *rope = (Rope*) malloc(sizeof(Rope));
    rope->x = x;
    rope->y = y;
    rope->width = width;
    rope->height = height;

    return rope;
}