#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void merge_sort(int *array, size_t size);

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);

/**
 * merge - Merges two sorted sub-arrays into one sorted segment
 * @array: The original array to sort
 * @buffer: Auxiliary array used for merging
 * @left: Start index of the left sub-array
 * @mid: End index of the left sub-array and start of right
 * @right: End index of the right sub-array
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right);

/**
 * top_down_split_merge - Recursively splits and sorts sub-arrays
 * @array: The original array to sort
 * @buffer: Auxiliary array for merging
 * @left: Start index of the current sub-array
 * @right: End index of the current sub-array
 */
void top_down_split_merge(int *array, int *buffer, size_t left, size_t right);

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void merge_sort(int *array, size_t size);

#endif /* SORT_H */
