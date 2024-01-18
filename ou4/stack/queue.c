#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"
#include "list.h"

/**
 * @file queue.c
 * @brief Definition of the type Queue.
 *
 * @author DV22ODM
 * @since 2022-12-05
 */

Queue *queue_create(void) {
    Queue *q = malloc(sizeof(Queue));
    q->list = list_create();
    return q;
}

void queue_destroy(Queue *q) {
    list_destroy(q->list);
    free(q);
}

void queue_enqueue(Queue *q, const char *value) {
    ListPos end = list_end(q->list);
    list_insert(end, value);
}

static char *clone_string(const char *in) {
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));
    strncpy(out, in, len);

    return out;
}

char *queue_dequeue(Queue *q) {
    ListPos head = list_first(q->list);
    char *value = clone_string(head.node->value);
    list_remove(head);
    return value;
}

bool queue_is_empty(const Queue *q) {
    return list_is_empty(q->list);
}
