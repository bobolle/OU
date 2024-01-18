#ifndef ARRAY_H
#define ARRAY_H

/** 
 * @mainpage
 * @author DV22ODM
 * @since 2022-11-18
 * 
 * Documentation for OU2.
 */

/**
 * @defgroup module Array
 * @anchor m_array
 *
 * @brief 2D Array inspired by the abstract datastructure Array.
 *
 * Elements in the 2D Array are integers.
 *
 * @author DV22ODM
 * @since 2022-11-18
 *
 * @{
 */

/** 
 * @brief The type for a 2D array.
 */
typedef struct array
{
    int n1; /**< Number of rows. */
    int n2; /**< Number of columns. */
    int *data; /**< Content of Array. */
} Array;

/**
 * @brief Create, allocate memory and return a zero array of size n1 rows by n2 columns.
 * @return The created Array.
 */
Array *array_create(int n1, int n2);

/**
 * @brief Deallocates an array.
 * @return Void.
 */
void array_destroy(Array *arr);

/**
 * @brief Get the number of rows.
 * @return Number of rows.
 */
int array_rows(const Array *arr);

/**
 * @brief Get the number of columns.
 * @return Number of columns.
 */
int array_columns(const Array *arr);

/**
 * @brief Return the value at row i1 and column i2 (zero-based indexing).
 * @param arr The Array.
 * @param i1 Row position.
 * @param i2 Column position.
 * @return Value of the position in Array.
 */
int array_get(const Array *arr, int i1, int i2);

/** 
 * @brief Set the value at row i1 and column i2 (zero-based indexing).
 * @param arr The Array.
 * @param i1 Row position.
 * @param i2 Column position.
 * @param value Desired value.
 * @return Void.
 */
void array_set(Array *arr, int i1, int i2, int value);

/**
 *  @}
 */

#endif /* ARRAY_H */
