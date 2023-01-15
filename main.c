#include <stdio.h>
#include "algo.h"
#include "graph.h"
#include "nodes.h"
#include "edges.h"


int main() {
    pnode head = NULL;
    int del;
    char in = ' ';
    while(scanf("%c ", &in) != EOF) {
        printf("%c, ",in);
        switch (in) {
            case 'A':
                build_graph_cmd(&head);
                break;
            case 'B':
                insert_node_cmd(&head);
                break;
            default:
                break;
            case 'D':
                scanf("%d", &del);
                delete_node_cmd(&head, del);
                printGraph_cmd(&head);
                break;

        }
    }
//            case 'S':
//                shortsPath_cmd(head);
//                break;
//            case 'T':
//                TSP_cmd(head);
//                break;


    return 0;
}
