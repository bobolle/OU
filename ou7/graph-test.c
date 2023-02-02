#include "graph.h"
#include <stdio.h>

int main(void) {
    graph *g = Make(1);
    insert_edge(g, 3, 0);
    insert_edge(g, 3, 1);
    insert_edge(g, 11, 1);
    print_all_edges(g);

    return 0;
}
