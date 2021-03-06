#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head);
    int size = 0;
    scanf("%d", &size);
    char n = 'A';
    scanf("%c", &n);
    for (int i = 0; i < size; ++i)
    {
        scanf("%c", &n);
        insert_node_cmd(head);
    }
}


pnode getNode(int id, pnode *head){
    pnode copy = *head;
    while(copy!=NULL) { 
        if(copy->node_num==id){
            return copy;}
        
        copy = copy->next;   
    }
    return NULL;

}


void delete_node_cmd(pnode *head){ 
    int data;
	scanf("%d", &data);
	pnode copy = *head;
	while (copy != NULL) {
		if (copy->edges != NULL &&copy->edges->dest->node_num == data) {
			pedge Redge = copy->edges;
			copy->edges = copy->edges->next;
			free(Redge);

		}
		copy = copy->next;
	}
	pnode temp = *head, next = *head;
	next = temp->next;
	while (next) {
		if (next->node_num == data) {
			temp->next = next->next;
			free(next);
			next = temp;

		}
		else {
			temp = next;
			next = temp->next;
		}
	}
}


void insert_node_cmd(pnode *head){
    int data = -1;
    scanf("%d", &data);
    pnode x = getNode(data,head);

    if (x == NULL){
        x = (pnode)malloc(sizeof(node));
        if (x == NULL)
        {
            return;
        }
        x->node_num = data;
        x->next = *head;
        x->edges = NULL;
        *head = x;
    }
    else{
        pedge i = x->edges;
        while (i != NULL){
            pedge temp = i->next;
            free(i);
            i = temp;
        }
        x->edges = NULL;
    }
    pedge *newEdge = &(x->edges);
    int dest = -1;
    int j = scanf("%d", &dest);
    while (j != 0 && j != EOF){
        pnode n_dest = getNode(dest,head);
        if (n_dest == NULL){
            n_dest = (pnode)malloc(sizeof(node));
            if (n_dest == NULL){
                return;
            }
            n_dest->node_num = dest;
            n_dest->edges = NULL;
            n_dest->next = *head;
            *head = n_dest;
        }
        int weight = -1;
        scanf("%d", &weight);

        *newEdge = (pedge)malloc(sizeof(edge));
        if ((*newEdge) == NULL){
            return;
        }
        (*newEdge)->weight = weight;
        (*newEdge)->dest = n_dest;
        (*newEdge)->next = NULL;
        newEdge = &((*newEdge)->next);
        j = scanf("%d", &dest);
    }
}


void printGraph_cmd(pnode head){
    pnode n = head; 
    while (n != NULL){
        printf("Node %d: ", n->node_num); 
        pedge e = n->edges;
        while (e != NULL){
            printf("D= %d: W= %d, ", e->dest->node_num, e->weight); 
            e = e->next;
        }
        printf("\n");
        n = n->next;
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










