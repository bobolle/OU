#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/**
 * @defgroup module List
 * @author dv22odm
 * @since 15-11-2022
 * @brief Doubly Linked List
 *
 * 
 *
 * @{
 */

/**
 * @brief The type for a node in the list.
 */
struct node
{
    struct node *next;
    struct node *prev;
    char *value;
};

/**
 * @brief The type for a list.
 */
typedef struct list
{
    struct node head;    
} List;

/**
 * @brief The type for a list position.
 */
typedef struct list_pos
{
    struct node *node;
} ListPos;

/**
 * @brief Create and return an empty list.
 *
 * @param void.
 * @return The created List.
 */
List *list_create(void);

/**
 * @brief Deallocate the list (and all of its values, if any).
 *
 * @param The List.
 * @return void.
 *
 */
void list_destroy(List *lst);

/** 
 * @brief Check if the list is empty.
 *
 * @param The List.
 * @return True if empty, else False.
 *
 */
bool list_is_empty(const List *lst);

/** 
 * @brief Get the position of the first element.
 * 
 * @param The List.
 * @return Position of the first element in the List.
 *
 */
ListPos list_first(List *lst);

/**
 * @brief Get the position after(!) the last element.
 *
 * @param The List.
 * @return Position after the last element in the List.
 *
 */
ListPos list_end(List *lst);

/** 
 * @brief Check equality between two positions.
 *
 * @param First position.
 * @param Second position.
 * @return True if p1 is equal to p2, else False.
 *
 */
bool list_pos_equal(ListPos p1, ListPos p2);

/**
 * @brief Forward to the next position.
 *
 * @param Current position.
 * @return The next position in our List.
 *
 */
ListPos list_next(ListPos pos);

/**
 * @brief Backward to the previous position.
 *
 * @param Current Position.
 * @return The previous position in our List.
 *
 */
ListPos list_prev(ListPos pos);

/**
 * @brief Insert the value before the position and return the position of the new element.
 *
 * @param Current position.
 * @param Value to be inserted in element.
 * @return Current position in our List.
 *
 */
ListPos list_insert(ListPos pos, const char *value);

/**
 * @brief Remove the value at the position and return the position of the next element.
 *
 * @param Current position.
 * @return Next position in our List.
 *
 */
ListPos list_remove(ListPos pos);

/** 
 * Get the value at the position.
 * 
 * @param Current position.
 * @return Value of element in current position.
 *
 */
const char *list_inspect(ListPos pos);

/**
 * @}
 */

#endif /* LIST_H */
