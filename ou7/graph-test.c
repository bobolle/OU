#include "graph.h"
#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void init_visit(graph *g);
void depthFirst(int n, graph *g);
void insert_edges(graph *g);

int main(void) {
    graph *g = create_graph(10);

    srand(time(NULL));
    insert_edges(g);

    init_visit(g);

    depthFirst(0, g);

    graph_print_all_edges(g);

    return 0;
}

void insert_edges(graph *g) {
    for (int i = 0; i < 20; i++) {
        int f_random = rand() % 20;
        int s_random = rand() % 20;

        graph_insert_edge(g, f_random, s_random);
    }

}

void init_visit(graph *g) {
    g->visit = malloc(g->node_count * sizeof(bool));
    for (int i = 0; i <= g->node_count; i++) {
        g->visit[i] = false;
    }
}

void depthFirst(int n, graph *g) {
    printf("visited: %d\n", n);
    g->visit[n] = true;
    set *neighbourSet = graph_neighbours(n, g);
    for (int v = 0; v < g->node_count; v++) {
        if (set_member_of(v, neighbourSet)) {
            if (!g->visit[v]) {
                depthFirst(v, g);
            }
        }
    }
}
