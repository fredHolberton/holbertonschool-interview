#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Sift-down operation to maintain max-heap.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @root: First element of the array
 * @end: Last element of the array
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left <= end && array[left] > array[largest])
		largest = left;
	if (right <= end && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		int temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, largest, end);
	}
}

/**
 * build_heap - Build a max-heap from the array.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void build_heap(int *array, size_t size)
{
	for (size_t i = (size / 2) - 1; i <= size; i--)
		sift_down(array, size, i, size - 1);
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	build_heap(array, size);

	for (ssize_t end = size - 1; end > 0; end--)
	{
		int temp = array[0];

		array[0] = array[end];
		array[end] = temp;
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}

