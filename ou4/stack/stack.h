#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @file stack.h
 * @defgroup module
 * @brief The type for a stack.
 *
 * @author DV22ODM
 * @since 2022-12-05
 *
 * @{
 */

/**
 * @brief The type for a stack.
 */
typedef struct stack
{
    int capacity;
    int size;
    double *data;
} Stack;


/**
 * @brief Create an empty stack.
 * @return The created stack.
 */
Stack *stack_create(void);

/** 
 * @brief Destroy the stack.
 * @parem s The stack.
 */
void stack_destroy(Stack *s);

/**
 * @brief Push a value onto the stack.
 * @parem s The stack.
 * @parem value The value.
 */
void stack_push(Stack *s, double value);

/**
 * @brief Pop the value at the top of the stack.
 * @parem s The stack.
 * @return Top value of the stack.
 */
double stack_pop(Stack *s);

/**
 * @brief Check if the stack is empty.
 * @parem s The stack.
 * @return True if stack is empty, else false.
 */
bool stack_is_empty(const Stack *s);

/**
 * @}
 */

#endif /* STACK_H */
