#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void printGraph_cmd(pnode head){
    if(!head){
        prinf("No graph to print");
        return;
    }
    pnode copy = head;
    while(copy->next){
        printf("Node ID: %d\n",copy->node_num);
        pedge copyEdge = copy->edges;
        while(copyEdge->next){
            printf("Node edges: Edge endpoint: %d, Edge weight: %d",copy->edges->endpoint,copy->edges->weight);
            copyEdge=copyEdge->next;
        }
        copy = copy->next;
    }
}


void deleteGraph_cmd(pnode *head){
    pnode nodeCurr = *head;
    while (nodeCurr!=NULL){
       pedge edgesCurr = nodeCurr->edges;
       while (edgesCurr!=NULL){
            pedge temp = edgesCurr;
            edgesCurr = edgesCurr->next;
            free(temp);
       }
       pnode temp = nodeCurr;
       nodeCurr=nodeCurr->next;
       free(temp);
    }
    *head=NULL;
}

void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head);
    int size;
    scanf("%d",&size);
    char n;
    scanf("%c",&n);
    int i;
    //A4n02533n20411n13702
    while(scanf("%d",i)==1){
        insert_node_cmd(head);
    }
    return;
}