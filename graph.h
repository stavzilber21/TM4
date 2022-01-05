#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode dest; 
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

// typedef struct Dijkstra {
//     pnode node;
//     int weight;
//     int tag;
//     struct Dijkstra *next;
// } dijkstra, *pdijkstra;


typedef struct Dijkstra_Node
{
    pnode node;
    struct Dijkstra_Node *dad;
    int weight;
    int isUse;
    struct Dijkstra_Node *next;
} Dnode, *pDnode;


pnode getNode(int id, pnode *head);
void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode head, int src, int dest);
int TSP_cmd(pnode head);

#endif
