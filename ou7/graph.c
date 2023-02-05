#include "graph.h"
#include "set.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * file: graph.c
 * author: DV22ODM
 * date: 2022-02-04
 * description: Definitions of the type Graph.
 */

graph *Make(int n) {
    graph *g = malloc(sizeof(graph));
    g->node_count = n;
    g->adjMatrix = malloc((n+1) * sizeof(set*));

    for (int i = 0; i <= n; i++) {
        g->adjMatrix[i] = set_empty();
    }

    return g;
}


void insert_edge(graph *g, int i, int j) {
    if (j > g->node_count) {
        expand_graph(g, j);
    }

    if (i > g->node_count) {
        expand_graph(g, i);
    }

    set_insert(i, g->adjMatrix[j]);
    set_insert(j, g->adjMatrix[i]);
}


set *neighbours(int node, graph *g) {
    return g->adjMatrix[node];
}


int no_of_nodes(graph *g) {
    return g->node_count;
}


void expand_graph(graph *g, int new_max) {
    g->adjMatrix = realloc(g->adjMatrix, (new_max +1) * sizeof(set*));

    for (int n = g->node_count +1; n <= new_max; n++) {
        g->adjMatrix[n] = set_empty();
    }

    g->node_count = new_max;
}


void print_all_edges(graph *g) {
    for (int i = 0; i <= g->node_count; i++) {
        int *a = set_get_values(g->adjMatrix[i]);
        printf("%d:", i);
        for (int j = 0; j < set_size(g->adjMatrix[i]); j++) {
            printf(" %d", a[j]);
        }
        printf("\n");
    }
}


void destory_graph(graph *g) {
    for (int i = 0; i <= g->node_count; i++) {
        free(g->adjMatrix[i]);
    }

    free(g->adjMatrix);
    free(g);
}
