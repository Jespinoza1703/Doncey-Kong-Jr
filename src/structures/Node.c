//
// Created by jessica on 16/09/19.
//

#include "Node.h"

Node* newNode(void *value){
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}