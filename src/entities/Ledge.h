//
// Created by jessica on 17/09/19.
//

#ifndef DONCEY_KONG_JR_LEDGE_H
#define DONCEY_KONG_JR_LEDGE_H

#include "../Util/GlobalVariables.h"

typedef struct
{
    double x, y, width, height;

} Ledge;


Ledge *newLedge(int x, int y, int width, int height);

#endif //DONCEY_KONG_JR_LEDGE_H
