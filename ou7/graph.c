#include "graph.h"
#include "set.h"
#include <stdlib.h>
#include <stdio.h>

graph *Make(int n) {
    graph *g = malloc(sizeof(graph));
    g->node_count = n;
    g->adjMatrix = malloc(n * sizeof(set*));

    for (int i = 0; i < n; i++) {
        g->adjMatrix[i] = set_empty();
    }

    return g;
}

void insert_edge(graph *g, int i, int j) {
    printf("max: %d, j:%d\n", g->node_count, j);

    if (g->node_count <= j) {
        g->adjMatrix = realloc(g->adjMatrix, j+1 * sizeof(set*));
        printf("nc: %d, j: %d\n", g->node_count, j);
        for (int n = g->node_count; n <= j; n++) {
            g->adjMatrix[n] = set_empty();
        }
        g->node_count = j;
    }

    //if (g->node_count <= i) {
    //    g->adjMatrix = realloc(g->adjMatrix, i+1 * sizeof(set*));
    //    for (int n = g->node_count; n <= i; n++) {
    //        g->adjMatrix[n] = set_empty();
    //    }
    //    g->node_count = i;
    //}

    //set_insert(i, g->adjMatrix[j]);
    set_insert(j, g->adjMatrix[i]);
}

void print_all_edges(graph *g) {
    printf("node count: %d\n", g->node_count);
    for (int y = 0; y < g->node_count; y++) {
        for (int i = 0; i < set_size(g->adjMatrix[y]); i++) {
            int *a = set_get_values(g->adjMatrix[y]);
            printf("(%d,%d)\n", y, a[i]);
        }
    }
}

int no_of_nodes(graph *g) {
    return g->node_count;
}

set *neighbours(graph *g, int node) {
    set *s = set_empty();
    return s;
}
