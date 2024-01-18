#include <stdio.h>
#include "table.h"

int main(void) {
    Table *tab = table_create(100);

    for (int n = 1; n <= 200; n++) {
        if (n > 50 && n < 61) {
            table_insert(tab, n, -n);
        }
        if (n > 140 && n < 161) {
            table_insert(tab, n, n*n);
        }
    }

    printf("Test the presence of added key/value pairs ... ");

    int pass = 1;
    for (int n = 1; n <= 200; n++) {
        int value;
        int key = n;
        if (n > 50 && n < 61) {
            if (table_lookup(tab, key, &value)) {
                pass = (value == -n);
            }
        }
        if (n > 140 && n < 161) {
            if (table_lookup(tab, key, &value)) {
                pass = (value == n*n);
            }
        }
        if (!pass) {
            pass = 0;
            break;
        }
    }

    if (pass) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    
    printf("Test the absence of non-added keys ... ");

    pass = 1;
    for (int n = 1; n <= 200; n++) {
        int value;
        int key = n;
        if (n < 51 || (n > 60 && n < 141) || n > 160) {
            if (table_lookup(tab, key, &value)) {
                pass = 0;
                break;
            }
        }
        if (!pass) {
            pass = 0;
            break;
        }
    }

    if (pass) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    table_destroy(tab);

    return 0;
}
