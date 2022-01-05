#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

pnode graph;
int weight;
int arrlenth;


pnode getNode(int id, pnode *head){
    pnode copy = *head;
    while(copy!=NULL) { 
        if(copy->node_num==id)
            return copy;
        else
            copy = copy->next;   
    }
    return NULL;

}

// void add_e(node *n, int dest , int weight, pnode *head ){
//     pedge e = n->edges;
//     while (e!=NULL){
//          e = e->next;
//     }
//     pedge new_edge =(pedge)malloc(sizeof(edge));
//     if(!new_edge) {
//         printf("error");
//         return;
//     }
//     pnode Node = getNode(dest,head);
//     new_edge->dest= &(*Node);
//     new_edge->weight =weight;
//     new_edge->next = NULL;
//     e->next=new_edge;
        
// }

// void add_edges(node *n,pnode *head){
//     int dest;
//     int weight;
//     while (scanf("%d",&dest)!=0 && scanf("%d",&weight)!=0){
//         if(n->edges!=NULL){
//             add_e(n,dest,weight,head);
//         }
//         else{
//             n->edges=(pedge)malloc(sizeof(edge));
//             if(!(n->edges)) {
//                 printf("error");
//                 return;
//     }
//             pnode Node = getNode(dest,head);
//             n->edges->dest = &(*Node);
//             n->edges->weight = weight;
//             n->edges->next = NULL;
//         }
//     }
    
// }

// void del_edges(pnode n){
//     if(n->edges!=NULL){
//         pedge temp = n->edges;
//         while(temp != NULL){
//             pedge p1 = NULL;
//             p1 = temp;
//             temp = temp->next;
//             free(p1);
//         }
//     }
//     else{
//         return;
//     }
// }

// void del_edge(pnode *head,int n)
// {
//     pnode tempNode = *head;

//     while (tempNode!= NULL)
//     {
//         if(tempNode->node_num != n && tempNode->edges!=NULL){

//             if(tempNode->edges->dest->node_num !=n)
//             {
//                 pedge tempEdge = tempNode->edges;

//                     while (tempEdge->next!= NULL)
//                     {   
//                         if(tempEdge->next->dest->node_num == n){
//                             pedge p1 = tempEdge->next;
//                             tempEdge->next=tempEdge->next->next;
//                             free(p1);
//                             break;
//                         }
//                         tempEdge = tempEdge->next;
//                     }           
//             }
//             else
//             { 
//                 if(tempNode->edges->next ==NULL)
//                     {
//                     pedge p1 = tempNode->edges;
//                     tempNode->edges = NULL;
//                     free(p1);
//                     }
//                 else{
//                     pedge p1 = tempNode->edges;
//                     tempNode->edges = p1->next;
//                     free(p1);
//                     }
//             }
//         }
//         tempNode = tempNode->next; 
//     }
// }


void delete_node_cmd(pnode *head) {
   if(! head){
        return;
    }
    if(!(*head))
        return;
    int num;
    scanf("%d" , &num);
    node * pointer =*head;
    while(pointer != NULL){

    if( pointer ->node_num ==num){
        node * pointer2 = pointer ->next;
        while(pointer2  !=NULL &&pointer2 ->node_num ==num ){
            pointer2 = pointer2 ->next;
        }

        if( &pointer == head){
            * head = pointer2;
        }
        if (&pointer != head){
            (*head) ->next = pointer2;
        }


        while(pointer !=pointer2){
            node * p= pointer;
            //free the edges
            pedge pf;
            pedge pass_edge =p ->edges;
            while (pass_edge){
                pf =pass_edge ;
                pass_edge = pass_edge->next;
                free(pf);
            }
            pointer =pointer->next;
            free(p);
        }

        }

        pointer = pointer ->next;

}

}


void insert_node_cmd(pnode *head){
    int id = -1;
    scanf("%d", &id);
    pnode src = getNode(id,head);

    if (src == NULL)
    {
        src = (pnode)malloc(sizeof(node));
        if (src == NULL)
        {
            return;
        }
        src->node_num = id;
        src->next = *head;
        src->edges = NULL;
        *head = src;
    }
    else
    {
        pedge index = src->edges;
        while (index != NULL)
        {
            pedge temp = index->next;
            free(index);
            index = temp;
        }
        src->edges = NULL;
    }
    pedge *lastEdge = &(src->edges);
    int dest = -1;
    int isDone = scanf("%d", &dest);
    while (isDone != 0 && isDone != EOF)
    {
        pnode destNode = getNode(dest,head);
        if (destNode == NULL)
        {
            destNode = (pnode)malloc(sizeof(node));
            if (destNode == NULL)
            {
                return;
            }
            destNode->node_num = dest;
            destNode->edges = NULL;
            destNode->next = *head;
            *head = destNode;
        }
        int weight = -1;
        scanf("%d", &weight);

        *lastEdge = (pedge)malloc(sizeof(edge));
        if ((*lastEdge) == NULL)
        {
            return;
        }
        (*lastEdge)->dest = destNode;
        (*lastEdge)->weight = weight;
        (*lastEdge)->next = NULL;
        lastEdge = &((*lastEdge)->next);
        isDone = scanf("%d", &dest);
    }
}


void printGraph_cmd(pnode head){
    pnode tempNode = head;
    while (tempNode != NULL)
    {
        printf("Node: %d {", tempNode->node_num);
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            printf("dest: %d weight: %d ", tempEdge->dest->node_num,tempEdge->weight);
            tempEdge = tempEdge->next;
        }
        printf("}");
        tempNode = tempNode->next;
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
    for (int i = 0; i < size; ++i){
        scanf("%c", &n);
        insert_node_cmd(head);
    }
}





// int main(){
//     pnode n = NULL;
//     pnode *head = &n;
//     build_graph_cmd(head);
//     insert_node_cmd(head);
//     delete_node_cmd(head);
//     deleteGraph_cmd(head);
//     printf("stav\n");
// }

