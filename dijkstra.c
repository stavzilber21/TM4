#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Dijkstra_Node
{
    pnode node;
    struct Dijkstra_Node *dad;
    int weight;
    int isUse;
    struct Dijkstra_Node *next;
} Dnode, *pDnode;

pnode graph;
int weight;
int arrlenth;


pDnode buildDijkstra_NodeList(pnode start, int src)
{
    pDnode head = NULL;
    pDnode *index = &head;
    while (start != NULL)
    {
        (*index) = (pDnode)malloc(sizeof(Dnode));
        if ((*index) == NULL)
        {
            return NULL;
        }
        
        (*index)->node = start;
        if (start->node_num == src)
        {
            (*index)->dad = (*index);
            (*index)->weight = 0;
        }
        else
        {
            (*index)->dad = NULL;
            (*index)->weight = __INT_MAX__;
        }
        (*index)->isUse = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }
    return head;
}
void deleteList(pDnode list) {
    while (list != NULL)
    {
        pDnode temp = list;
        list = list->next;
        free(temp);
    }
}
pDnode getPDnode(pDnode list, int want)
{
    while (list != NULL)
    {
        if (list->node->node_num == want)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}
pDnode minInList(pDnode head)
{
    pDnode ans = NULL;
    while (head != NULL)
    {
        if (!head->isUse && head->weight < __INT_MAX__ && (ans == NULL || ans->weight < head->weight))
        {
            ans = head;
        }
        head = head->next;
    }
    if (ans != NULL)
    {
        ans->isUse = 1;
    }
    return ans;
}
int shortsPath_cmd(pnode head, int src, int dest){
    pDnode list = buildDijkstra_NodeList(head, src);

    pDnode u = minInList(list);
    while (u != NULL)
    {
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
            //relax
            pDnode v = getPDnode(list, edgeIndex->dest->node_num);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist)
            {
                v->weight = newDist;
                v->dad = u;
            }
            edgeIndex = edgeIndex->next;
        }
        u = minInList(list);
    }
    int dis = getPDnode(list, dest)->weight;
    dis = (dis == __INT_MAX__)? -1: dis;
    deleteList(list);
    return dis;
}

void input_Array(int* fromArr,int* toArr, int arrLenght) 
{
    for (int i = 0; i < arrLenght; ++i) 
    {
        toArr[i] = fromArr[i];
    }
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j] = temp;
}

void PermotitionOfArr(int* arr, int arrLength)
{
    
    int tempWeight = 0;
    for (int i = 0; i < arrLength-1; ++i) 
    {
        int D = shortsPath_cmd(graph,arr[i], arr[i+1]);
        if (D == -1)
        {
            tempWeight = __INT_MAX__;
            return;
        }
        tempWeight += D;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}

void permotion( int start ,int* arr, int arrLength){
    if (start == arrLength -1 ){
        PermotitionOfArr(arr, arrLength);
        return;
    }
    for (int i = start; i < arrLength; ++i) {
        int* arrCopy = (int*)(calloc(arrLength, sizeof(int)));
        input_Array(arr,arrCopy,arrLength);
        swap(arrCopy,start, i);
        permotion(start + 1, arrCopy, arrLength);
        free(arrCopy);
    }
}

int TSP_cmd(pnode head)
{
    weight = __INT_MAX__;
	arrlenth = -1;
    graph = head;
    scanf("%d", &arrlenth);
    int *arr = (int *) (calloc(arrlenth, sizeof(int)));

    for (int i = 0; i < arrlenth; i++) {
        scanf("%d", &arr[i]);
    }
    int *arrCopy = (int *) (calloc(arrlenth, sizeof(int)));
    input_Array(arr,arrCopy,arrlenth);
    permotion(0,arrCopy,arrlenth);
    free(arr);
    free(arrCopy);
    if (weight == __INT_MAX__){
        weight = -1;
    }
    return weight;
}
