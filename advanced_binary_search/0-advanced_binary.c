#include <stdio.h>
#include <stddef.h>
#include "search_algos.h"

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Recursively searches for a value in a sorted array
 * @array: Pointer to the first element of the array
 * @left: Left boundary of the search
 * @right: Right boundary of the search
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (binary_search_recursive(array, left, mid, value));
	}
	else if (array[mid] < value)
	{
		return (binary_search_recursive(array, mid + 1, right, value));
	}
	else
	{
		return (binary_search_recursive(array, left, mid - 1, value));
	}
}

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 *                   (recursively and returns first occurrence)
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, (int)(size - 1), value));
}
