#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_node_cmd(pnode *head);

void printGraph_cmd(pnode *head);

//A sizeNodes nodeNum
void build_graph_cmd(pnode *head) {
    if (*head != NULL) {
        deleteGraph_cmd(head);
        *head = NULL;
    }
    int sizeNodes;
    scanf("%d", &sizeNodes);

    for (int i = 0; i < sizeNodes; i++) {
        insertLast(i, head);
    }
    char n;
    int dst;
    int src;
    int w;
    for (int i = 0; i < sizeNodes; i++) {
        scanf("%c ", &n); //must be n for the first time
        scanf("%d", &src);
        while (scanf("%d", &dst) != 0) {
            scanf("%d", &w);
            createEdge(src, dst, w, head);
        }
    }
    printGraph_cmd(head);
    return;
}

//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 B 5 0 4 2 1 B 2 1 3 5 1
void insert_node_cmd(pnode *head) {
    int numNode;
    scanf("%d", &numNode); // the number of the node
    printf("%d \n", numNode);
    pnode p = *head;
    size_t ex = exists(numNode, head);
    if (ex) {
        while (p) {
            if (p->node_num == numNode) {
                break;
            }
            p = p->next;
        }
        pedge e = p->edges;
        pedge *prevE = &(p->edges);
        while (e) {
            *prevE = e->next;
            free(e);
            e = *prevE;
        }
    }


    int dst;
    int w;
    char in = scanf("%d", &dst);
    while ((in != 0) && (in != EOF)) {
        scanf("%d", &w);
        if (ex) {
            createEdge(numNode, dst, w, head );
        } else {
            insertLast(numNode, head);
            ex = 1;
            createEdge(numNode, dst, w, head);
        }
        in = scanf("%d", &dst);
    }

    printGraph_cmd(head);
    return;
}

void delete_node_cmd(pnode *head, int del) {
    if (!*head)
        return;
    pnode p = *head;
    pnode *prev = head;
    while (p) {
        pedge e = p->edges;
        pedge *prevE = &(p->edges);
        if (p->node_num == del) {
            while (e) {
                *prevE = e->next;
                free(e);
                e = *prevE;
            }
        } else {
            while (e) {
                if (e->endpoint->node_num == del) {
                    *prevE = e->next;
                    free(e);
                    e = *prevE;
                } else {
                    prevE = &(e->next);
                    e = e->next;
                }
            }
        }
        prev = &(p->next);
        p = p->next;
    }
    p = *head;
    prev = head;
    while (p) {
        if (p->node_num == del) {
            *prev = p->next;
            free(p);
            p = *prev;
            return;
        } else {
            prev = &(p->next);
            p = p->next;
        }
    }
    return;
}

//for self debug
void printGraph_cmd(pnode *head) {
    if (!*head) {
        printf("EMPTY GRAPH\n");
        return;
    }
    pnode p = *head;
    while (p) {
        pedge e = p->edges;
        if(e) {
            while (e) {
                printf("(%d)----%d---->(%d)\n", p->node_num,e->weight,e->endpoint->node_num);
                e = e->next;
            }
        }
        else{
            printf("(%d)\n",p->node_num);
        }
        p = p->next;
    }
    return;
}

void deleteGraph_cmd(pnode *head) {
    pnode p = *head;
    while (p) {
        delete_node_cmd(head, p->node_num);
        p = p->next;
    }
    printGraph_cmd(head);
    return;
}

void shortsPath_cmd(pnode head);

void TSP_cmd(pnode head);

