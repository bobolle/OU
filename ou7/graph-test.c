#include "graph.h"
#include <stdio.h>

int main(void) {
    graph *g = Make(1);
    insert_edge(g, 3, 0);
    insert_edge(g, 10, 0);
    insert_edge(g, 7, 1);
    print_all_edges(g);
    printf("number of nodes: %d\n", no_of_nodes(g));

    return 0;
}
