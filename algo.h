#include "graph.h"

typedef struct PRIORITY_QUEUE_{
    pnode data;
    struct PRIORITY_QUEUE_* next;

}priorityQueue , *ppriority;

int isEmpty(ppriority * head);
void push(ppriority * head,pnode);
void pop(ppriority * head);
ppriority peek(ppriority * head);
ppriority newNode(pnode);
void shafel(ppriority *head);

void build_graph_cmd(pnode *head);