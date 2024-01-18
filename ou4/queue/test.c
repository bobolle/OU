#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

int main(void)
{
    Queue *q = queue_create();

    char str[] = "A";
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        str[0] = ch;
        queue_enqueue(q, str);
    }

    bool ok = true;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        str[0] = ch;
        char *str2 = queue_dequeue(q);
        if (strcmp(str, str2) != 0) {
            printf("%s %s\n", str, str2);
            ok = false;
        }
        free(str2);
    }
    if (!queue_is_empty(q)) {
        ok = false;
    }
    printf("Test the functioning of the queue ... %s\n", ok ? "PASS" : "FAIL");

    queue_destroy(q);

    return 0;
}
