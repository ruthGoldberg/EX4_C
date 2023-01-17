#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999999

void insert_node_cmd(pnode *head);

void printGraph_cmd(pnode *head);

void permute(pnode head ,int *arr, int l, int r);

int min = INF;

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
    return;
}

//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 B 5 0 4 2 1 B 2 1 3 5 1
void insert_node_cmd(pnode *head) {
    int numNode;
    scanf("%d", &numNode); // the number of the node
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
            createEdge(numNode, dst, w, head);
        } else {
            insertLast(numNode, head);
            ex = 1;
            createEdge(numNode, dst, w, head);
        }
        in = scanf("%d", &dst);
    }

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
            p = (*prev);
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
        if (e) {
            while (e) {
                printf("(%d)----%d---->(%d)\n", p->node_num, e->weight, e->endpoint->node_num);
                e = e->next;
            }
        } else {
            printf("(%d)\n", p->node_num);
        }
        p = p->next;
    }
    return;
}

void deleteGraph_cmd(pnode *head) {
    pnode p = *head;
    pnode del ;
    while (p) {
        del= p->next;
        delete_node_cmd(head, p->node_num);
        p = del;
    }
    return;
}

void shortsPath_cmd(pnode head, int src, int dest) {

    ppriority queue = NULL;

    // all node dist is 0
    pnode p = head;
    while (p != NULL) {
        if (p->node_num != src) {
            p->dist = INF;
        } else{
            p->dist = 0;
        }
        push(&queue, p);
        p = p->next;
    }
    pedge e;
    //check the dist between the first vert to its next vert is less
    while (!isEmpty(&queue)) {
        shafel(&queue);
        p=pop(&queue);
        if(p->dist == INF){
            while (!isEmpty(&queue)){
                ppriority fr= pop(&queue);
            }
            return;
        }

        e = p->edges;
        while (e) {
            if (p->dist + e->weight < e->endpoint->dist) {
                e->endpoint->dist = p->dist + e->weight;
            }
            e = e->next;
        }

    }
    return;

}


void TSP_cmd(pnode head) {
    min = INF;
    int arr_len;
    scanf("%d", &arr_len);
    int arrPerm[arr_len];
    for (int i = 0; i < arr_len; i++) {
        scanf("%d", &arrPerm[i]);
    }
    permute(head , arrPerm , 0 ,arr_len-1);
    if(min == INF)
        min = -1;
    printf("TSP shortest path: %d \n",min);

}

void permute(pnode head ,int *arr, int l, int r) {
    int sum = 0;
    if (l == r) {
        for (int i = 0; i < r; i++){
            shortsPath_cmd(head , arr[i] , arr[i+1]);
            pnode p = head;
            p=head;
            while (p){
                if(p->node_num != arr[i+1])
                    p=p->next;
                else break;
            }

            sum += p->dist ;
        }
        if(sum < min)
            min = sum;
    }

     else {
        for (int i = l; i <= r; i++) {
            // Swapping done
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;

            // Recursion called
            permute(head,arr, l + 1, r);

            //backtrack
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}




