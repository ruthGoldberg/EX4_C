#include <malloc.h>
#include <stdio.h>
#include "algo.h"


void shafel(ppriority *head){
    ppriority first = *head;
    ppriority temp = (*head)->next;
    ppriority help;
    ppriority * prev = head;
    //finding the min
    while (temp) {
        if (temp->data->dist < first->data->dist) {
            *prev = temp;
            help=temp->next;
            first->next=help;
            temp->next=first;
            head=prev;
            break;
        }
        temp = temp->next;
    }
    first = *head;

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
        if (start->next == NULL) {
            start->next = temp;
        } else {
            temp->next = start->next;
            start->next = temp;
        }
    }
}

void pop(ppriority *head) {
    ppriority temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

ppriority peek(ppriority *head) {
    return (*head);
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