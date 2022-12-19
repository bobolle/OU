#include <stdio.h>
#include <stdbool.h>
#include "set.h"

void test_comp(const set *s2, const set *s3);
void test_uid(const set *su, const set *si, const set *sd);
void test_insert_remove_values(const set *s, const set *s2, const set *s3);

int main(void) {
    set *s = set_empty();
    set *s2 = set_single(10);
    set *s3 = set_single(400);

    set_insert(15, s2);
    set_insert(30, s2);
    set_insert(45, s2);
    set_insert(60, s2);

    set_remove(60, s2);

    set_insert(10, s3);
    set_insert(15, s3);
    set_insert(30, s3);
    set_insert(45, s3);

    test_insert_remove_values(s, s2, s3);

    set *su = set_union(s2, s3);
    set *si = set_intersection(s2, s3);
    set *sd = set_difference(s2, s3);

    test_uid(su, si, sd);

    test_comp(s2, s3);

    printf("Random value from s2: %d\n", set_choose(s2));
    printf("Random value from s3: %d\n", set_choose(s3));

    set_destroy(s);
    set_destroy(s2);
    set_destroy(s3);

    return 0;
}

void test_comp(const set *s2, const set *s3) {
    printf("Test if subset and equal is working ... ");
    int pass = true;

    if (!set_subset(s2, s3)) {
        pass = false;
    }

    if (set_equal(s2, s3)) {
        pass = false;
    }

    if (pass) {
        printf("PASS.\n");
    } else {
        printf("FAIL.\n");
    }
}

void test_uid(const set *su, const set *si, const set *sd) {
    printf("Test if union, intersection and difference is working ... ");
    const int *au = set_get_values(su);
    const int *ai = set_get_values(si);
    const int *ad = set_get_values(sd);

    int pass = true;

    for (int i = 0; i < set_size(su); i++) {
        if (!(au[i] == 10 || au[i] == 15 || au[i] == 30 || au[i] == 45 || au[i] == 400)) {
            pass = false;
            break;
        }
    }

    for (int i = 0; i < set_size(si); i++) {
        if (!(ai[i] == 10 || ai[i] == 15 || ai[i] == 30 || ai[i] == 45)) {
            pass = false;
            break;
        }
    }

    for (int i = 0; i < set_size(sd); i++) {
        if (!(ad[i] == 400)) {
            pass = false;
            break;
        }
    }

    if (pass) {
        printf("PASS.\n");
    } else {
        printf("FAIL.\n");
    }
}

void test_insert_remove_values(const set *s, const set *s2, const set *s3) {
    printf("Test if values was inserted correctly ... ");

    int *a2 = set_get_values(s2);
    int *a3 = set_get_values(s3);

    int pass = true;

    if (!set_is_empty(s)) {
        pass = false;
    }

    // testing s2
    for (int i = 0; i < set_size(s2); i++) {
        if (!(a2[i] == 10 || a2[i] == 15 || a2[i] == 30 || a2[i] == 45)) {
            pass = false;
            break;
        }
    }

    // testing s3
    for (int i = 0; i < set_size(s3); i++) {
        if (!(a3[i] == 10 || a3[i] == 15 || a3[i] == 30 || a3[i] == 45 || a3[i] == 400)) {
            pass = false;
            break;
        }
    }

    if (pass) {
        printf("PASS.\n");
    } else {
        printf("FAIL.\n");
    }
}
