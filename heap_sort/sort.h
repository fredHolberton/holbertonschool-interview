#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);

/**
 * sift_down - Sift-down operation to maintain max-heap.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @root: First element of the array
 * @end: Last element of the array
 */
void sift_down(int *array, size_t size, size_t root, size_t end);

/**
 * build_heap - Build a max-heap from the array.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void build_heap(int *array, size_t size);

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
