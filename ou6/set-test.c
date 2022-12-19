#include <stdio.h>
#include "set.h"

int main(void) {
    set *s = set_empty();
    set_insert(10, s);
    set_insert(2, s);

    set *s1 = set_empty();
    set_insert(10, s1);
    set_insert(2, s1);
    set_insert(24, s1);

    printf("Equal: %d\n", set_equal(s, s1));
    printf("Subset: %d\n", set_subset(s, s1));

    set_remove(2, s);
    set_remove(10, s);
    printf("Empty: %d\n", set_is_empty(s));

    int *a = set_get_values(s1);
    int i = 0;

    printf("Testing set_get_values:\n");
    while (i < set_size(s1)) {
        printf("%d\n", a[i]);
        i++;
    }

    printf("Random: %d\n", set_choose(s1));

    set_destroy(s);
    set_destroy(s1);

    return 0;
}
