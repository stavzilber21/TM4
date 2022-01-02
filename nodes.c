#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

void delete_node_cmd(pnode *head) {
    int data;
    scanf("%d",&data);
    pnode copy = *head;
    if(!*head) return; //if the list is empty

    if(copy->node_num == data){ //if this is the head of the list
        pnode next_curr = copy->next;
        copy->next = next_curr->next;
        pedge edge = next_curr->edges;
        pedge i;
        while (edge != NULL) {
                i = edge;
                edge = edge->next;
                free(i); //free the edge
            }
        copy=copy->next;
        free(copy);
        return;
    }


    while(copy->next) {
            if (copy->next->node_num == data) {
                pnode next_curr = copy->next;
                copy->next = next_curr->next;
                pedge edge = next_curr->edges;
                pedge i;
                while (edge != NULL) {
                    i = edge;
                    edge = edge->next;
                    free(i); //free the edge
                }
                free(next_curr); //free the node
            }
            copy=copy->next;
        }



}


// void insert_node_cmd(pnode *head){
//     int data;
//     scanf("%d",&data);
//     node* new = (node*) malloc(sizeof(node)); //allocate memory
//     if(!new) {
//         printf("error");
//         return;
//     }
//     // int Data =atoi(data)
//     new -> node_num = data; //initiate new node
//     new -> next = NULL;
    
//     //A4n02533n20411n13702

//     //is there an edge?
//     pedge first = (pedge)malloc(sizeof(pedge));
//     pnode firstNode = (pnode)malloc(sizeof(pnode));
//     if(!first || !firstNode){
//             printf("error");
//             return;
//         }
//     int nameOfFirst;
//     scanf("%d",&nameOfFirst);
//     firstNode -> node_num = nameOfFirst;
//     int weightOfFirst;
//     scanf("%d",&weightOfFirst);
//     first -> weight = weightOfFirst;
//     first -> endpoint = firstNode;
    
//     new -> edges = first;
//     int neighborId;
//     While(scanf("%d",&neighborId)){
//         //lets find the new edge endpoint
//         pnode neighborDest;
//         neighborDest -> node_num = neighborId;

//         //aren't we overrunning the same memory with malloc???
//         //make new edge and add node as end point
//         edge neighborEdge = (edge)malloc(sizeof(edge));
//         if(!neighborEdge){
//             printf("error");
//             return;
//         }
//         //get its weight
//         int neighborWeight;
//         scanf("%d",&neighborWeight);

//         neighborEdge->weight = neighborWeight;
//         neighborEdge->endpoint = neighborDest;

//         //lets add the edge to the end of the list
//         edge *hold;
//         pedge hold = *first;
//         while(hold->next) { //while the next of copy is not null
//             hold = hold->next;
//         }
//         hold -> next= neighborEdge; //add to new edge in the end of the list;
        
//     }
//     if(!(*head)){ //if the list is empty
//         *head=new;
//         return;
//     }
//     pnode copy = *head;
//     while(copy->next) { //while the next of copy is not null
//         if(copy->node_num=data)
//             delete_node_cmd(copy);
//         else{
//             copy = copy->next;
//         }
//     }
//     copy -> next= new; //add new node in the end of the list;
//     return;
// }

int main(){
    int id = 1;
    pnode n = id;
    pnode *head = &n;
    delete_node_cmd(head);
    // insert_node_cmd(head);
    printf("stav\n");
}
