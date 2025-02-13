#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "bs_tree.h"

BSTree *bs_tree_make(int value) {
    BSTree *tree = malloc(sizeof(BSTree));
    tree->value = value;
    tree->left_child = NULL;
    tree->right_child = NULL;
    return tree;
}

BSTreePos bs_tree_insert_left(int value, BSTreePos pos) {
    struct node *child = malloc(sizeof(struct node));
    child->value = value;
    child->left_child = NULL;
    child->right_child = NULL;
    pos->left_child = child;
    return child;
}

BSTreePos bs_tree_insert_right(int value, BSTreePos pos) {
    struct node *child = malloc(sizeof(struct node));
    child->value = value;
    child->left_child = NULL;
    child->right_child = NULL;
    pos->right_child = child;
    return child;
}

int bs_tree_inspect_label(BSTreePos pos) {
    return pos->value;
}

bool bs_tree_has_left_child(BSTreePos pos) {
    return !(pos->left_child == NULL);
}

bool bs_tree_has_right_child(BSTreePos pos) {
    return !(pos->right_child == NULL);
}

BSTreePos bs_tree_root(BSTree *tree) {
    return tree;
}

BSTreePos bs_tree_left_child(BSTreePos pos) {
    return pos->left_child;
}

BSTreePos bs_tree_right_child(BSTreePos pos) {
    return pos->right_child;
}

void bs_tree_destroy(BSTree *tree) {
    if (bs_tree_has_left_child(tree)) {
        bs_tree_destroy(bs_tree_left_child(tree));
    }
    if (bs_tree_has_right_child(tree)) {
        bs_tree_destroy(bs_tree_right_child(tree));
    }
    free(tree);
}
