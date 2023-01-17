#include <malloc.h>
#include <stdio.h>
#include "algo.h"


void shafel(ppriority *head) {


    ppriority first = *head;
    ppriority next = (*head)->next;
    while (next) {
        if (next->data->dist < first->data->dist) {
            pnode temp = next->data;
            next->data = first->data;
            first->data = temp;
        }
        next = next->next;
    }
}


int isEmpty(ppriority *head) {
    return (*head) == NULL;
}

void push(ppriority *head, pnode var) {
    ppriority start = (*head);

    // Create new Node
    ppriority temp = newNode(var);
    if (*head == NULL) {
        (*head) = temp;
        return;
    }

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->data->dist > temp->data->dist) {
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    } else {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL && start->next->data->dist <= temp->data->dist) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

pnode pop(ppriority *head) {
    if(*(head) == NULL)
        return NULL;
    ppriority temp = *head;
    pnode poped = (*head)->data;
    (*head) = (*head)->next;
    free(temp);
    return poped;
}


ppriority newNode(pnode var) {
    ppriority temp = (ppriority) malloc(sizeof(priorityQueue));
    if (temp == NULL) {
        printf("error\n");
        return 0;
    }
    temp->next = NULL;
    temp->data = var;
    return temp;
}