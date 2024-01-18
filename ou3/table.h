#ifndef TABLE_H
#define TABLE_H

#include <stdbool.h>

/**
 * @file table.h
 * @defgroup module Table
 * @brief Table inspired by the abstract datastructure Table.
 *
 * @author DV22ODM
 * @since 2022-11-28
 *
 * @{
 */


/**
 * @brief The type for a bucket.
 */
struct bucket
{
    int key;
    int value;
    bool used;
};

/**
 * @brief The type for the table.
 */
typedef struct table
{
    int capacity; /** The number of buckets. */
    struct bucket *buckets; /** The bucket array. */
} Table;

/**
 * @brief Create an empty table.
 * @param capacity The number of buckets.
 * @return The created table.
 */
Table *table_create(int capacity);

/**
 * @brief Destroy the table.
 * @param tab The table.
 */
void table_destroy(Table *tab);

/**
 * @brief Lookup the value for a key and return false if the key is not found.
 * @param tab The table.
 * @param key The key for the element to look up.
 * @param value Gets value of the element.
 * @return Returns true if element with key exists, false if not.
 */
bool table_lookup(Table *tab, int key, int *value);

/**
 * @brief Insert a key/value pair and overwrite the value if the key exists.
 * Up to user to keep track if table is full.
 * @param tab The table.
 * @param key The key you want to insert in the table.
 * @param value The value you want to insert in the table.
 */
void table_insert(Table *tab, int key, int value);

/**
 * @}
 */
#endif /* TABLE_H */
