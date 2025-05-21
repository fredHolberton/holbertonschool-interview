#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Number of nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_last_node - Finds the last node in a binary heap (level-order)
 * @root: Pointer to the root node
 * @index: Current index (used in recursion)
 * @target: Index of the node to find
 * Return: Pointer to the node or NULL
 */
binary_tree_t *get_last_node(binary_tree_t *root, size_t index, size_t target)
{
	binary_tree_t *node = NULL;

	if (!root)
		return (NULL);
	if (index == target)
		return (root);
	node = get_last_node(root->left, 2 * index + 1, target);
	if (node)
		return (node);
	return get_last_node(root->right, 2 * index + 2, target);
}

/**
 * heapify_down - Restores Max Heap property by sifting down
 * @root: Pointer to the root node
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		int tmp = root->n;

		root->n = largest->n;
		largest->n = tmp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int value = (*root)->n;
	size_t size = binary_tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Get last node by level-order index */
	heap_t *last = get_last_node(*root, 0, size - 1);

	/* Swap last node’s value into root */
	(*root)->n = last->n;

	/* Remove the last node */
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	/* Restore heap property */
	heapify_down(*root);

	return (value);
}
