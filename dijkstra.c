#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//In this class are the functions of shortest_path and tsp
//There are several auxiliary functions for each function


pnode graph;
int weight;
int len;

////shortestPath

pdijkstra use_Dijkstra(pdijkstra head, int id) 
{
    while (head != NULL) 
    {
        if (head->node->node_num == id) {
            return head;
        }

        head = head->next;
    }
    return NULL;
}

void del_Dijk(pdijkstra dijkstra) 
{
    while (dijkstra != NULL)
    {
        pdijkstra temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

pdijkstra min(pdijkstra head) 
{
    pdijkstra Node = NULL;

    while (head != NULL) 
    {
        if (!head->tag && head->weight < INFINITY && (Node == NULL || Node->weight < head->weight)) 
        {
            Node = head;
        }
        head = head->next;
    }
    if (Node != NULL) 
    {
        Node->tag = 1;
    }
    return Node;
}

pdijkstra RunDijkstra(pnode open, int src) 
{
    pdijkstra head = NULL;
    pdijkstra *n = &head;

    while (open != NULL) 
    {
        (*n) = (pdijkstra) malloc(sizeof(dijkstra));
        if ((*n) == NULL) 
        {
            exit(0);
        }

        (*n)->node = open;
        if (open->node_num == src)
        {
            (*n)->weight = 0;
        } 
        else 
        {
            (*n)->weight = INFINITY;
        }
        (*n)->tag = 0;
        (*n)->next = NULL;
        n = &((*n)->next);
        open = open->next;
    }
    return head;
}


int shortsPath_cmd(pnode head, int src, int dest) 
{
    pdijkstra dijkstraHead = RunDijkstra(head, src);
    pdijkstra temp = min(dijkstraHead);
    
    while (temp != NULL) 
    {
        pedge E_ind = temp->node->edges;

        while (E_ind != NULL) 
        {
            pdijkstra n = use_Dijkstra(dijkstraHead, E_ind->dest->node_num);

            int res = temp->weight + E_ind->weight;
            if (n->weight > res)
            {
                n->weight = res;
            }
            E_ind = E_ind->next;
        }
        temp = min(dijkstraHead);
    }
    
    int D = use_Dijkstra(dijkstraHead, dest)->weight;
    
    if (D == INFINITY)
    {
        D = -1;
    }
    del_Dijk(dijkstraHead);
    
    return D;
}





///tsp

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j] = temp;
}

void permutation_array(int* arr, int len){
    int curr = 0;
    for (int i = 0; i < len-1; ++i){
        int dist = shortsPath_cmd(graph,arr[i], arr[i+1]);
        if (dist == -1){
            curr = INFINITY;
            return;
        }
        curr += dist;
    }
    if (curr < weight){
        weight = curr;
    }
}

void arr_input(int* a,int* b, int len) {
    for (int i = 0; i < len; ++i){
        b[i] = a[i];
    }
}


void permutation( int index ,int* arr, int len){
    if (index == len -1 ){
        permutation_array(arr, len);
        return;
    }
    for (int i = index; i < len; ++i) {
        int* newArr = (int*)(calloc(len, sizeof(int)));
        arr_input(arr,newArr,len);
        swap(newArr,index, i);
        permutation(index + 1, newArr, len);
        free(newArr);
    }
}

int TSP_cmd(pnode head){   ////The main function
    weight = INFINITY ;
	len = 0;
    graph = head;
    scanf("%d", &len);
    int *arr = (int *) (calloc(len, sizeof(int)));

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    int *newArr = (int *) (calloc(len, sizeof(int)));
    arr_input(arr,newArr,len);
    permutation(0,newArr,len);
    free(arr);
    free(newArr);
    if (weight == INFINITY){
        weight = -1;
    }
    return weight;
}





