//
// Created by jessica on 16/09/19.
//

#include "Node.h"

#ifndef DONCEY_KONG_JR_LINKEDLIST_H
#define DONCEY_KONG_JR_LINKEDLIST_H


typedef struct{

    Node *head;
    int size;

}LinkedList;


LinkedList *newList();
int getSize(LinkedList *list);
void insertNode(LinkedList *list, Node *node);
void deleteNode(LinkedList *list, Node *node);
Node *getNode(LinkedList *list, int index);




#endif //DONCEY_KONG_JR_LINKEDLIST_H
