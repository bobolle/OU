#ifndef GRAPH.H
#define GRAPH.H

#include "set.h"

graph *graph_empty();
graph graph_make(int n);
graph graph_insert-edge(edge e, graph g);
