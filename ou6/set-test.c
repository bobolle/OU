#include <stdio.h>
#include "set.h"

int main(void) {
    set *s = set_empty();
    set_insert(10, s);
    set_insert(2, s);

    //set_remove(2, s);

    int *a = set_get_values(s);
    int i = 0;
    while (i < set_size(s)) {
        printf("%d\n", a[i]);
        i++;
    }
    return 0;
}
