#ifndef GRAPH_
#define GRAPH_
#define infinity 100000
typedef struct GRAPH_NODE_ *pnode;;

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

typedef struct dijkstra
{
    pnode node;
    struct dijkstra *dad;
    int weight;
    int isIn;
    struct dijkstra *next;
} dij_node, *p_dij_node;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head);
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode head, int src, int dest);
int TSP_cmd(pnode head);

#endif
