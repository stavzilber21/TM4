#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(pnode *head){
    deleteGraph_cmd(head);
    int size = 0;
    scanf("%d", &size);
    char n = 'A';
    scanf("%c", &n);
    for (int i = 0; i < size; ++i){
        scanf("%c", &n);
        insert_node_cmd(head);
    }
}

pnode getNode(pnode *head, int id){
    pnode curr = *head;
    while (curr != NULL){
        if (curr->node_num == id){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head){
    int data = 0;
    scanf("%d", data);
    pnode new = getNode(head, data);
    if (new == NULL){
        new = (pnode)malloc(sizeof(node)); //allocate memory to the new node
        if (new == NULL){
            return;
        }
        new->node_num = data;
        new->next = *head; //add new to the list start
        new->edges = NULL;
        *head = new;
    }
    else{ // if the vertex already exists
        pedge ed = new->edges;
        while (ed != NULL){
            pedge temp = ed;
            ed = ed ->next;
            free(temp);    //erase all the edges that enter it
        }
        new->edges = NULL;
    }
    pedge *newEdge = &(new->edges);
    int dest = -1;
    int isDone = scanf("%d", &dest);
    while (isDone != 0 && isDone != EOF)
    {
        pnode destNode = getNode(head, dest);
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

        *newEdge = (pedge)malloc(sizeof(edge));
        if ((*newEdge) == NULL)
        {
            return;
        }
        (*newEdge)->dest = destNode;
        (*newEdge)->weight = weight;
        (*newEdge)->next = NULL;
        newEdge = &((*newEdge)->next);
        isDone = scanf("%d", &dest);
    }
}
void printGraph_cmd(pnode head)
{
    pnode nodeIndex = head;
    while (nodeIndex != NULL)
    {
        printf("Node %d: ", nodeIndex->node_num);
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL)
        {
            printf("dest %d: weight %d, ", edgeIndex->dest->node_num, edgeIndex->weight);
            edgeIndex = edgeIndex->next;
        }
        printf("\n");
        nodeIndex = nodeIndex->next;
    }
}
void deleteGraph_cmd(pnode *head)
{
    pnode nodeIndex = *head;
    while (nodeIndex != NULL)
    {
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL)
        {
            pedge temp = edgeIndex;
            edgeIndex = edgeIndex->next;
            free(temp);
        }
        pnode temp = nodeIndex;
        nodeIndex = nodeIndex->next;
        free(temp);
    }
    *head = NULL;
}
void delete_node_cmd(pnode *head)
{
    int key = -1;
    scanf("%d", &key);
    pnode nodeIndex = *head;
    pnode *isFirst = NULL;
    pnode prevAns = NULL;
    if (nodeIndex->node_num == key)
    {
        isFirst = head;
    }

    while (nodeIndex != NULL)
    {
        if (nodeIndex->next != NULL && nodeIndex->next->node_num == key)
        {
            prevAns = nodeIndex;
        }
        if (nodeIndex->edges != NULL && nodeIndex->edges->dest->node_num == key)
        {
            pedge temp = nodeIndex->edges;
            nodeIndex->edges = nodeIndex->edges->next;
            free(temp);
            nodeIndex = nodeIndex->next;
            continue;
        }
        pedge edgeIndex = nodeIndex->edges;
        if (edgeIndex != NULL)
        {
            while (edgeIndex->next != NULL)
            {
                if (edgeIndex->next->dest->node_num == key)
                {
                    pedge temp = edgeIndex->next;
                    edgeIndex->next = temp->next;
                    free(temp);
                }
                else
                {
                    edgeIndex = edgeIndex->next;
                }
            }
        }
        nodeIndex = nodeIndex->next;
    }

    if (isFirst != NULL)
    {
        pedge edgeIndex = (*isFirst)->edges;
        while (edgeIndex != NULL)
        {
            pedge temp = edgeIndex;
            edgeIndex = edgeIndex->next;
            free(temp);
        }
        pnode temp = *isFirst;
        *isFirst = temp->next;
        free(temp);
    }
    else if (prevAns != NULL)
    {
        pnode remove = prevAns->next;
        pedge edgeIndex = remove->edges;
        while (edgeIndex != NULL)
        {
            pedge temp = edgeIndex;
            edgeIndex = edgeIndex->next;
            free(temp);
        }
        prevAns->next = remove->next;
        free(remove);
    }
}
