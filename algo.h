#include "graph.h"

typedef struct PRIORITY_QUEUE_{
    pnode data;
    int priority;
    struct PRIORITY_QUEUE_* next;

}priorityQueue , *ppriority;

void build_graph_cmd(pnode *head);