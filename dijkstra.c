#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


p_dij_node buildDijkstra_NodeList(pnode start, int src){
    p_dij_node head = NULL;
    p_dij_node *index = &head;
    while (start != NULL){
        (*index) = (p_dij_node)malloc(sizeof(dij_node));
        if ((*index) == NULL){
            return NULL;
        }
        
        (*index)->node = start;
        if (start->node_num == src){
            (*index)->dad = (*index);
            (*index)->weight = 0;
        }
        else{
            (*index)->dad = NULL;
            (*index)->weight = infinity;
        }
        (*index)->isIn = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }
    return head;
}
void deleteList(p_dij_node list){
    while (list != NULL){
        p_dij_node temp = list;
        list = list->next;
        free(temp);
    }
}
p_dij_node getPDnode(p_dij_node list, int want){
    while (list != NULL){
        if (list->node->node_num == want){
            return list;
        }
        list = list->next;
    }
    return NULL;
}
p_dij_node minInList(p_dij_node head){
    p_dij_node ans = NULL;
    while (head != NULL){
        if (!head->isIn && head->weight < infinity && (ans == NULL || ans->weight < head->weight)){
            ans = head;
        }
        head = head->next;
    }
    if (ans != NULL){
        ans->isIn = 1;
    }
    return ans;
}
int shortsPath_cmd(pnode head, int src, int dest){
    p_dij_node list = buildDijkstra_NodeList(head, src);
    p_dij_node u = minInList(list);
    while (u != NULL){
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL){
            p_dij_node v = getPDnode(list, edgeIndex->dest->node_num);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist){
                v->weight = newDist;
                v->dad = u;
            }
            edgeIndex = edgeIndex->next;
        }
        u = minInList(list);
    }
    int dis = getPDnode(list, dest)->weight;
    dis = (dis == infinity)? -1: dis;
    deleteList(list);
    return dis;
}