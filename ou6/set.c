#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "set.h"

/*
 * file: set.c
 * author: DV22ODM
 * date: 2022-12-11
 * description: Definitions of the type Set as Bitvector.
 */

struct set {
    int capacity;   // How many bits the set contains.
    int size;       // Amount of current members.
    char *array;    // Bitvector as array of char.
};


set *set_empty()
{
    set *s = malloc(sizeof(set));
    s->capacity = 8;
    s->size = 0;
    s->array = malloc(sizeof(char));
    s->array[0] = 0;

    return s;
}


set *set_single(const int value)
{
    int bit_in_array = value; // To make the code easier to read
    int no_of_bytes = bit_in_array / 8 + 1;

    set *s = malloc(sizeof(set));
    s->size = 1;
    s->capacity = no_of_bytes * 8;
    s->array = malloc(no_of_bytes * sizeof(char));

    for (int i = 1 ; i < no_of_bytes ; i++) {
        s->array[i] = 0;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    s->array[byte_no] = s->array[byte_no] | 1 << bit;

    return s;
}


void set_insert(const int value, set *s)
{
    if (!set_member_of(value, s)) {
        int bit_in_array = value; // To make the code easier to read

        // Increase the capacity if necessary
        if (bit_in_array >= s->capacity) {
            int no_of_bytes = bit_in_array / 8 + 1;
            s->array = realloc(s->array, no_of_bytes);
            for (int i = s->capacity / 8 ; i < no_of_bytes ; i++) {
                s->array[i] = 0;
            }
            s->capacity = no_of_bytes * 8;
        }

        // Set the bit
        int byte_no = bit_in_array / 8;
        int bit = 7 - bit_in_array % 8;
        s->array[byte_no] = s->array[byte_no] | 1 << bit;
        s->size++;
    }
}


set *set_union(const set *const s1, const set *const s2)
{
    set *s = set_empty();

    for (int i = 0 ; i < s1->capacity || i < s2->capacity ; i++) {
        if (set_member_of(i, s1) || set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }

    return s;
}


set *set_intersection(const set *const s1, const set *const s2)
{
    set *s = set_empty();

    for (int i = 0 ; i < s1->capacity || i < s2->capacity ; i++) {
        if (set_member_of(i, s1) && set_member_of(i, s1)) {
            set_insert(i, s);
        }
    }

    return s;
}


set *set_difference(const set *const s1, const set *const s2)
{
    set *s = set_empty();

    for (int i = 0 ; i < s1->capacity || i < s2->capacity ; i++) {
        if (set_member_of(i, s1) && !set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }

    return s;
}


bool set_is_empty(const set *const s)
{
    if (set_size(s) == 0) {
        return true;
    } else {
        return false;
    }
}


bool set_member_of(const int value, const set *const s)
{
    int bit_in_array = value; // To make the code easier to read

    if (bit_in_array >= s->capacity) {
        return false;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    char the_byte = s->array[byte_no];

    return the_byte & 1 << bit;
}


int set_choose(const set *const s)
{
    int r = rand() % set_size(s);
    int *a = set_get_values(s);

    return a[r];
}


void set_remove(const int value, set *const s)
{
    if (set_member_of(value, s)) {
        int bit_in_array = value; // To make the code easier to read
        int byte_no = bit_in_array / 8;
        int bit = 7 - bit_in_array % 8;

        s->array[byte_no] = s->array[byte_no] & 0 << bit;
        s->size--;
    }
}


bool set_equal(const set *const s1, const set *const s2)
{
    if ((s1->capacity == s2->capacity) && (set_size(s1) == set_size(s2))) {
        int no_of_bytes = s1->capacity / 8;
        int i = 0;

        while (i != no_of_bytes) {
            if (s1->array[i] != s2->array[i]) {
                return false;
            }

            i++;
        }

        return true;
    } else {
        return false;
    }
}


bool set_subset(const set *const s1, const set *const s2)
{
    int s1_no_of_bytes = s1->capacity / 8;
    int s2_no_of_bytes = s2->capacity / 8;

    int i = 0;
    while (i < s1_no_of_bytes && i < s2_no_of_bytes) {
        if ((s1->array[i] & s2->array[i]) != s1->array[i]) {
            return false;
        }

        i++;
    }

    return true;
}


int set_size(const set *const s)
{
    return s->size;
}


int *set_get_values(const set *const s)
{
    if (!set_is_empty(s)) {
        int *a = malloc(set_size(s) * sizeof(int));
        int index_of_array = 0;
        int index_of_set = 0;

        while (index_of_set != s->capacity) {
            if (set_member_of(index_of_set, s)) {
                a[index_of_array] = index_of_set;
                index_of_array++;
            }

            index_of_set++;
        }

        return a;
    } else {
        return NULL;
    }
}

void set_destroy(set *s)
{
    free(s->array);
    free(s);
}
