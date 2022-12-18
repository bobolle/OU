#include "set.h"

int main(void) {
    set *s = set_empty();
    set_insert(10, s);

    set *s2 = set_single(8);

    return 0;
}
