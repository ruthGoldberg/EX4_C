#include "graph.h"

typedef struct PRIORITY_QUEUE_{
    pnode data;
    struct PRIORITY_QUEUE_* next;

}priorityQueue , *ppriority;

int isEmpty(ppriority * head);
void push(ppriority * head,pnode);
pnode pop(ppriority * head);
ppriority newNode(pnode);
void shafel(ppriority *head);
void permute(pnode head ,int *arr, int l, int r);
