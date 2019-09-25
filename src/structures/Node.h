//
// Created by jessica on 16/09/19.
//

#include <stdlib.h>

#ifndef DONCEY_KONG_JR_NODE_H
#define DONCEY_KONG_JR_NODE_H

typedef struct Node Node;

struct Node{
    Node *next;
    void *value;
};

Node *newNode(void *value);

#endif //DONCEY_KONG_JR_NODE_H
