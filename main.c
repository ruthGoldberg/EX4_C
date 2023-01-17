#include <stdio.h>
#include "algo.h"
#include "graph.h"
#include "nodes.h"
#include "edges.h"

#define INF 999999

int main() {
    pnode head = NULL;
    pnode p;
    int src, dest;
    int del;
    char in = ' ';
    while(scanf("%c ", &in) != EOF) {
        switch (in) {
            case 'A':
                build_graph_cmd(&head);
                break;
            case 'B':
                insert_node_cmd(&head);
                break;

            case 'D':
                scanf("%d", &del);
                delete_node_cmd(&head, del);
                break;
            case 'S':
                scanf("%d", &src);
                scanf("%d", &dest);
                shortsPath_cmd(head , src , dest);
                int shortPath;
                p=head;
                while (p){
                    if(p->node_num != dest)
                        p=p->next;
                    else break;
                }
                if(p->dist == INF){
                    shortPath= -1;
                }
                shortPath= p->dist;
                printf("Dijsktra shortest path: %d \n",shortPath);
                break;
            case 'T':
                TSP_cmd(head);
                break;

            default:
                break;
        }
    }
    deleteGraph_cmd(&head);
    




    return 0;
}
