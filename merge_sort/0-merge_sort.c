#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into one sorted segment
 * @array: The original array to sort
 * @buffer: Auxiliary array used for merging
 * @left: Start index of the left sub-array
 * @mid: End index of the left sub-array and start of right
 * @right: End index of the right sub-array
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;
	size_t x;

	printf("Merging...\n");
	printf("[left]: ");
	for (x = left; x < mid; x++)
	{
		printf("%d", array[x]);
		if (x + 1 < mid)
			printf(", ");
	}
	printf("\n[right]: ");
	for (x = mid; x < right; x++)
	{
		printf("%d", array[x]);
		if (x + 1 < right)
			printf(", ");
	}
	printf("\n");

	while (i < mid && j < right)
		buffer[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];
	while (i < mid)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	for (x = left; x < right; x++)
	{
		printf("%d", array[x]);
		if (x + 1 < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * top_down_split_merge - Recursively splits and sorts sub-arrays
 * @array: The original array to sort
 * @buffer: Auxiliary array for merging
 * @left: Start index of the current sub-array
 * @right: End index of the current sub-array
 */
void top_down_split_merge(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	top_down_split_merge(array, buffer, left, mid);
	top_down_split_merge(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	top_down_split_merge(array, buffer, 0, size);
	free(buffer);
}
