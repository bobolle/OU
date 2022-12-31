#include "graph.h"
#include "set.h"

#include <stdlib.h>

graph *graph_empty() {
    graph *g = malloc(sizeof(graph));
    g->v = set_empty();
    g->e = set_empty();
    return g;
}
