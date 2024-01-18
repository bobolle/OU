#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "list.h"

/**
 * @file queue.h
 * @defgroup module
 * @brief The type for the queue.
 *
 * @author DV22ODM
 * @since 2022-12-05
 *
 * @{
 */

/**
 * @brief The type for a Queue.
 */
typedef struct queue
{
    List *list;
} Queue;

/**
 * @brief Create and return an empty queue.
 * @return The created queue.
 */
Queue *queue_create(void);

/**
 * @brief Destroy the queue.
 * @param q The Queue.
 */
void queue_destroy(Queue *q);

/**
 * @brief Add a value to the tail of the queue.
 * The value is copied to dynamically allocated memory. 
 * @param q The Queue.
 * @param value The value.
 */
void queue_enqueue(Queue *q, const char *value);

/**
 * @brief Remove the value at the head of the queue.
 * The caller is responsible for deallocating the returned pointer.
 * @parem q The Queue.
 * @return The value of the removed head.
 */
char *queue_dequeue(Queue *q);

/**
 * @brief Check if the queue is empty.
 * @param q The Queue.
 * @return True if empty, else false.
 */
bool queue_is_empty(const Queue *q);

/**
 * @}
 */

#endif /* QUEUE_H */
