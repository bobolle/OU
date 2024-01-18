#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

void check_value(Stack *s);

int main(void) {

    Stack *s = stack_create();

    for (int n = 1; n <= 10; n++) {
        stack_push(s, pow(n, 0.5));
    }

    check_value(s);

    stack_destroy(s);
    return 0;
}

void check_value(Stack *s) {
    bool pass = true;
    int n;
    while (!stack_is_empty(s)) {
        n = s->size;
        if (stack_pop(s) != pow(n, 0.5)) {
            pass = false;
            break;
        }
    }

    printf("Test the functioning of the stack ... %s\n", pass ? "PASS" : "FAIL");
}
