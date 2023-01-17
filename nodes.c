#include <malloc.h>
#include "nodes.h"
#include "graph.h"

pnode createNodes(int n){
    pnode head = (pnode) malloc (sizeof (node));
    if (head == NULL){
        printf("Error");
        return 0;
    }
    head->node_num= n;
    head ->edges = NULL;
    head ->next = NULL;
    head->dist=0;
    return head;
}

void insertLast(int n, pnode *head) {
    pnode *p = head;
    while(*p)
        p = &((*p)->next);
    *p = createNodes(n);
}

int exists(int num , pnode * head){
    pnode p = *head;

    while (p) {

        if (p->node_num == num) {
            return 1;
        }
        p = p->next;
    }

    return 0;
}