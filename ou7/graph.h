#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"

/**
 * @file graph.h
 * @module 
 * @brief Graph as Array of Set, inspired by the abstract datastructure Graph.
 *
 * @author DV22ODM
 * @since 2022-02-04
 *
 * @ {
*/

/**
 * @brief The type for the graph.
 */
typedef struct graph {
    int node_count;
    bool *visit;
    set **adjMatrix;
} graph;

/**
 * @brief Creates a new graph.
 *
 * Creates a new graph with only n amount of nodes.
 * 
 * @param n Amount of how many nodes the new graph will have.
 * @return The created graph.
 */
graph *Make(int n);


/**
 * @brief Inserts an edge.
 *
 * Inserts an edge between two nodes i, j.
 *
 * @param i The first node in the edge.
 * @param j The second node in the edge.
 */
void insert_edge(graph *g, int i, int j);


/**
 * @brief Neighbours amount.
 *
 * Returns a set with the amount of neighbours of one specific node.
 * Must be a node contained in the graph.
 *
 * @param node The node.
 * @param g The graph.
 *
 * @return Set of neighbours of the node.
 */
set *neighbours(int node, graph *g);


/**
 * @brief Number of nodes.
 *
 * Returns the amount of nodes contained in the graph.
 *
 * @param g The graph.
 *
 * @return The amount of nodes.
 */
int no_of_nodes(graph *g);


/**
 * @brief Expands the graph.
 *
 * Expands the graph when it's size is too small for the node to be inserted.
 *
 * @param g The graph.
 * @param new_max New size of the graph.
 */
void expand_graph(graph *g, int new_max);


/**
 * @brief Print all edges.
 *
 * Prints out all the edges contained in the graph.
 * Used for diagnostic purposes.
 *
 * @param g The graph.
 */
void print_all_edges(graph *g);


/**
 * @brief Destroy graph.
 *
 * Free the memory set to the graph in the heap.
 * Used when a graph is no longer needed.
 *
 * @param g The graph.
 */
void destory_graph(graph *g);

/**
 * @ }
 */

#endif /* GRAPH_H */
