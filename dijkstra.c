#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//In this class are the functions of shortest_path and tsp
//There are several auxiliary functions for each function


pnode graph;
int weight;
int len;

////shortestPath

void help1_toDeleltList(pdij list) { 
    while (list != NULL){
        pdij temp = list;
        list = list->next;
        free(temp);
    }
}


pdij help2_build_dijkstra(pnode h_node, int x){
    pdij head = NULL;
    pdij *temp = &head;
    while (h_node != NULL)
    {
        (*temp) = (pdij)malloc(sizeof(dij)); //allocate mamory
        if ((*temp) == NULL){
            return NULL;
        }
        (*temp)->node = h_node;
        if (h_node->node_num == x){
            (*temp)->prev = (*temp);
            (*temp)->weight = 0;
        }
        else{
            (*temp)->prev = NULL;
            (*temp)->weight = INFINITY ;
        }
        (*temp)->isIN = 0;
        (*temp)->next = NULL;
        temp = &((*temp)->next);
        h_node = h_node->next;
    }
    return head;
}

pdij help3_find_min(pdij head){
    pdij result = NULL;
    while (head != NULL){
        if (!head->isIN && head->weight < INFINITY  && (result == NULL || result->weight < head->weight)){
            result = head;
        }
        head = head->next;
    }
    if (result != NULL){
        result->isIN = 1;
    }
    return result;
}


pdij help4_getDijNode(int x, pdij List){
    while (List != NULL){
        if (List->node->node_num == x){
            return List;
        }
        List = List->next;
    }
    return NULL;
}

int shortsPath_cmd(pnode head, int src, int dest){  //The main function
    pdij list = help2_build_dijkstra(head, src);
    pdij node_u = help3_find_min(list);
    while (node_u != NULL){
        pedge Edge = node_u->node->edges;
        while (Edge != NULL){
            pdij node_v = help4_getDijNode(Edge->dest->node_num,list);
            int dist = node_u->weight + Edge->weight;
            if (node_v->weight > dist){
                node_v->weight = dist;
                node_v->prev = node_u;
            }
            Edge = Edge->next;
        }
        node_u = help3_find_min(list);
    }
    int res = help4_getDijNode(dest,list)->weight;
    res = (res == INFINITY )? -1: res;
    help1_toDeleltList(list);
    return res;
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





