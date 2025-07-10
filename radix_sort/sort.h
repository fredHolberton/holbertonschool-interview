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
 * radix_sort - Sorts an array of integers using LSD Radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
