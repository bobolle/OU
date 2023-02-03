#ifndef GRAPH_H
#define GRAPH_H
#include "set.h"

typedef struct graph {
    int node_count;
    bool *visit;
    set **adjMatrix;
} graph;

graph *Make(int n);
void insert_edge(graph *g, int i, int j);
set *neighbours(int node, graph *g);
int no_of_nodes(graph *g);
void expand_graph(graph *g, int new_max);
void print_all_edges(graph *g);
void destory_graph(graph *g);

#endif
