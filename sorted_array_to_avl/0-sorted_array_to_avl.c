#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to convert to AVL tree.
 * @size: The size of the array.
 *
 * Return: Pointer to the root node of the AVL tree or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0)
		return NULL;

	size_t mid = (size % 2 ==0) ? (size / 2 - 1) : (size / 2);
	avl_t *root = (avl_t *)malloc(sizeof(avl_t));

	if (!root)
		return NULL;
	root->n = array[mid];
	root->parent = NULL;
	root->left = sorted_array_to_avl(array, mid);
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	return root;
}


