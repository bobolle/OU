#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * @brief Allocate memory for node value.
 *
 * @param in as char*.
 * @return Adress of allocated memory.
 *
 */
static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));

    strncpy(out, in, len);

    return out;
}

/**
 * @brief Create a node and return a node.
 *
 * @param value as char*, value of the node.
 * @return Adress of the created node.
 */
static struct node *make_node(const char *value)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->value = clone_string(value);

    return temp;
}


List *list_create(void)
{
    List *temp = malloc(sizeof(List));
    temp->head.next = &temp->head;
    temp->head.prev = &temp->head;
    temp->head.value = NULL;
    return temp;
}


void list_destroy(List *lst)
{
    if(lst->head.next != NULL) {
        ListPos p = list_first(lst);
        while(!list_is_empty(lst)) {
            p = list_remove(p);
        }
        free(lst);
    }
}


bool list_is_empty(const List *lst)
{
    if (lst->head.next == &lst->head) {
        return true;
    }
    else {
        return false;
    }
}


ListPos list_first(List *lst)
{
    ListPos pos = {
        .node = lst->head.next
    };

    return pos;  
}


ListPos list_end(List *lst)
{
    ListPos pos = {
        .node = &lst->head
    };
return pos;
}


bool list_pos_equal(ListPos p1, ListPos p2)
{
    return (p1.node == p2.node) ? true : false;
}


ListPos list_next(ListPos pos)
{
    pos.node = pos.node->next;
    return pos;
}


ListPos list_prev(ListPos pos)
{
    pos.node = pos.node->prev;
    return pos;
}


ListPos list_insert(ListPos pos, const char *value)
{
    // Create a new node.
    struct node *node = make_node(value);

    // Find nodes before and after (may be the same node: the head of the list).
    struct node *before = pos.node->prev;
    struct node *after = pos.node;

    // Link to node after.
    node->next = after;
    after->prev = node;

    // Link to node before.
    node->prev = before;
    before->next = node;

    // Return the position of the new element.
    pos.node = node;
    return pos;
}


ListPos list_remove(ListPos pos)
{
    struct node *before = pos.node->prev;
    struct node *after = pos.node->next;
    
    before->next = after;
    after->prev = before;

    free(pos.node->value);
    free(pos.node);

    pos.node = after;

    return pos;
}


const char *list_inspect(ListPos pos) {
    return pos.node->value;
}
