#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void print_array(int *array, int left, int right);

/**
 * binary_search_recursive - Recursively searches for a value in a sorted array
 * @array: Pointer to the first element of the array
 * @left: Left boundary of the search
 * @right: Right boundary of the search
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, int left, int right, int value);

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 *                   (recursively and returns first occurrence)
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present or array is NULL
 */
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */

