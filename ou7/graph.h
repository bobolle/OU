#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"

typedef struct graph {
    set *v;
    set *e;
} graph;

graph *graph_empty();
//graph graph_make(int n);
//graph graph_insert-edge(edge e, graph g);

//isempty
//hasnoedge
//choosenode
//neighbours
//deletenode
//deleteedge
#endif
