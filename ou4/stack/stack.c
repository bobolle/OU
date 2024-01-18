#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

/**
 * @file stack.c
 * @brief Definitions of the type Stack.
 *
 * @author DV22ODM
 * @since 2022-12-05
 */

Stack *stack_create(void) {
    Stack *s = malloc(sizeof(Stack));
    s->capacity = 5;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(double));
    return s;
}

void stack_destroy(Stack *s) {
    free(s->data);
    free(s);
}

void stack_push(Stack *s, double value) {
    printf("size: %d    cap: %d\n", s->size, s->capacity);
    if (s->size >= s->capacity) {
        printf("before: %d\n", s->capacity);
        s->capacity += s->capacity;
        s->data = realloc(s->data, s->capacity * sizeof(double));
        printf("after: %d\n", s->capacity);
    }
    s->data[s->size] = value;
    s->size++;
}

double stack_pop(Stack *s) { 
    s->size--;
    return s->data[s->size];
}

bool stack_is_empty(const Stack *s) {
    return (s->size == 0);
}
