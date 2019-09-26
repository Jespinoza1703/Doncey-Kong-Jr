//
// Created by jessica on 16/09/19.
//

#include "LinkedList.h"

/*
 * Allocates memory for the linked list.
 */
LinkedList *newList(){

    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

/*
 * Adds a node to the end list.
 */
void insertNode(LinkedList *list, Node* node){
    if(list->head == NULL)
        list->head = node;

    else{
        Node* head = list->head;
        while(head->next != NULL)
            head = head->next;
        head->next = node;
    }
    list->size++;
}

/*
 * Deletes a node from the list.
 */
void deleteNode(LinkedList *list, Node* node) {
    Node *tmp = list->head;
    Node *deleted;
    if (tmp == node) {
        deleted = tmp;
        list->head = node->next;
        free(deleted);
    } else {
        while (tmp->next != node)
            tmp = tmp->next;
        deleted = tmp->next;
        tmp->next = deleted->next;
        free(deleted);
    }
}

/*
 * Returns the length of the list.
 */
int getSize(LinkedList *list){
    return list->size;
}