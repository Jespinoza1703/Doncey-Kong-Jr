//
// Created by jessica on 18/09/19.
//

#ifndef DONCEY_KONG_JR_COLLISIONS_H
#define DONCEY_KONG_JR_COLLISIONS_H


#include "../entities/Monkey.h"
#include "../entities/Ledge.h"
#include "../Util/GlobalVariables.h"
#include "../structures/LinkedList.h"

void ledgeCollision(Monkey *monkey, Ledge **ledges);
int crocoCollision(Monkey *monkey, LinkedList *crocos);


#endif //DONCEY_KONG_JR_COLLISIONS_H
