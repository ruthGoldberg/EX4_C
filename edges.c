#include <malloc.h>
#include "graph.h"
#include "edges.h"

void createEdge(int src, int dest, int weight, pnode *head) {
    size_t s, d;
    s = 0;
    d = 0;

    pedge newEdge = (pedge) malloc(sizeof (edge));
    if (newEdge == NULL) {
        printf("Error");
        return;
    }
    newEdge->weight = weight;
    newEdge ->next = NULL;
    newEdge ->endpoint =NULL;
    pnode p = *head;
    pedge travelEdge;
    while (p) {
        if (p->node_num == src) {
            s = 1;
            if (p->edges == NULL) {
                p->edges = newEdge;
            }
            else {
                travelEdge = p->edges;
                while (travelEdge->next != NULL) {
                    travelEdge = travelEdge->next;
                }
                travelEdge->next = newEdge;
            }
        }
        if (p->node_num == dest) {
            newEdge->endpoint = p;
            d = 1;
        }//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T
        if (s && d) {
            return;
        }
        p = p->next;
    }

}