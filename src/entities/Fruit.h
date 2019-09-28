//
// Created by jessica on 18/09/19.
//

#ifndef DONCEY_KONG_JR_FRUIT_H
#define DONCEY_KONG_JR_FRUIT_H


#include "Rope.h"

typedef struct
{
    float x, y;
    int width, height;
    int type;
    Rope *rope;
    int relativePos;

} Fruit;

void setFruit(Fruit *fruit);


#endif //DONCEY_KONG_JR_FRUIT_H
