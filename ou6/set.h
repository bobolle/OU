#ifndef SET_H
#define SET_H

#include <stdbool.h>

/**
 * @file set.h
 * @defgroup module
 * @brief Set as Bitvector inspired by the abstract datasturcture Set.
 * 
 * @author DV22ODM
 * @since 2022-12-05
 *
 * @ {
 */


/**
 * @brief The type for the set.
 */
typedef struct set set;

/**
 * @brief Creates a new empty set.
 * @return The created empty set.
 */
set *set_empty();

/**
 * @brief Creates a new set with a single member (value).
 * @param value The value.
 * @return The created set.
 */
set *set_single(const int value);

/**
 * @brief Inserts the value in the set.
 * @param value The value.
 * @param s The set.
 */
void set_insert(const int value, set *s);

/**
 * @brief Returns a new set that is the union of the two sets.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return The union of the first and second set.
 */
set *set_union(const set *const s1, const set *const s2);

/**
 * @brief Returns a new set that is the intersection of the two sets.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return The intersection of the first and second set.
 */
set *set_intersection(const set *const s1, const set *const s2);

/**
 * @brief Returns a new set that is the difference of the two sets (s1 \ s2).
 * @param s1 The first set.
 * @param s2 The second set.
 * @return The difference between the first and second set.
 */
set *set_difference(const set *const s1, const set *const s2);

/**
 * @brief Checks if the set is empty.
 * @param s The set.
 * @return True if empty, else false.
 */
bool set_is_empty(const set *const s);
/**
 * @brief Checks if the value is a member of the set.
 * @param value The Value.
 * @param s The set.
 * @return True if value is a member of the set, else false.
 */
bool set_member_of(const int value, const set *const s);

/**
 * @brief Returns a random member of the set (without removing it).
 * @param s The set.
 * @return A random member of the set.
 */
int set_choose(const set *const s);

/**
 * @brief Removes the value from the set.
 * Function checks before removing if value is a member of the set.
 * @param value The value.
 * @param s The set.
 */
void set_remove(const int value, set *const s);

/** 
 * @brief Checks if the two sets are equal.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return True if the two set are equal, else false.
 */
bool set_equal(const set *const s1, const set *const s2);

/**
 * @brief Checks if the first set is a subset of the second set.
 * @param s1 The first set.
 * @param s2 The second set.
 * @return True if the first set is a subset of the second set, else false.
 */
bool set_subset(const set *const s1, const set *const s2);

/**
 * @brief Returns an array with all the values in the set.
 * @param s The set.
 * @return Array with all values from set. Returns NULL if set is empty.
 */
int *set_get_values(const set *const s);

/**
 * @brief Returns the number of elements in the set.
 * @param s The set.
 * @return The number of elements in the set.
 */
int set_size(const set *const s);

/**
 * @brief Destroys the set.
 * @param s The set.
 */
void set_destroy(set *s);

/**
 * @}
 */

#endif /* SET_H */
