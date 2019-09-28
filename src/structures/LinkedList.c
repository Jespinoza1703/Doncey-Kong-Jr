//
// Created by jessica on 16/09/19.
//

#include <stdio.h>
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
    if(list->head == NULL) {
        list->head = node;
        list->size++;
    }

    else{
        Node* tmp = list->head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
        list->size++;
    }
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
    list->size--;
}

/*
 * Returns the length of the list.
 */
int getSize(LinkedList *list){
    return list->size;
}


Node *getNode(LinkedList *list, int index){

    if(index < list->size + 1){
        Node *result;
        int count = 0;
        Node *tmp = list->head;
        while (tmp != NULL)
        {
            if(index != count){
                count++;
                tmp = tmp->next;
            }
            else{
                result = tmp;
                break;
            }
        }
        return  result;
    }
    else{
        printf("List index out of range \n");
    }

}
