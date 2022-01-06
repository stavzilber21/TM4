#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main(){
    pnode n = NULL;
    pnode *head = &n;
    char index;
    while (scanf("%c", &index) != EOF)
    {
        if (index == 'A'){
            build_graph_cmd(head);
        }
        else if (index == 'B'){
            insert_node_cmd(head);
        }
        else if (index == 'D'){
            delete_node_cmd(head);
        }
        else if (index == 'S'){
            int src=-1;
            int dest=-1;
            scanf("%d, %d\n", &src, &dest);
            int dist = shortsPath_cmd(*head,src,dest);
            printf("the shortest path is: %d \n", dist);
        }
        else if (index == 'T'){
            int tsp = TSP_cmd(*head);
            printf("the TSP shortest path is: %d \n", tsp);
        }
    }
    deleteGraph_cmd(head);
    return 0;
}