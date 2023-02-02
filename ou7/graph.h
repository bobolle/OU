#ifndef GRAPH_H
#define GRAPH_H
#include "set.h"

typedef struct graph {
    int node_count;
    set **adjMatrix;
} graph;

graph *Make(int n);
void insert_edge(graph *g, int row, int col);
void print_all_edges(graph *g);

//neighbours
int no_of_nodes(graph *g);

#endif
