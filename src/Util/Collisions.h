//
// Created by jessica on 18/09/19.
//

#ifndef DONCEY_KONG_JR_COLLISIONS_H
#define DONCEY_KONG_JR_COLLISIONS_H


#include "../entities/Monkey.h"
#include "../entities/Ledge.h"
#include "../Util/GlobalVariables.h"
#include "../structures/LinkedList.h"
#include "../entities/Crocodile.h"
#include "../entities/Rope.h"
#include "../entities/Fruit.h"

void ledgeCollision(Monkey *monkey, Ledge **ledges);
int crocoCollision(Monkey *monkey, LinkedList *crocos);
int ropeCollision(Monkey *monkey, Rope **ropes);
int fruitCollision(Monkey *monkey, LinkedList *fruits);


#endif //DONCEY_KONG_JR_COLLISIONS_H
