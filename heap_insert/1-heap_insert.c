#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_insertion_parent - Finds the insertion parent in a Max binary Heap
 * @root: Pointer to the root node
 *
 * Return: Pointer to the parent where the new node should be inserted
 */
heap_t *find_insertion_parent(heap_t *root)
{
	heap_t *file[1024];
	int currentIndex = 0;
	int maxIndex = 0;

        file[maxIndex] = root;
	maxIndex++;

        while (currentIndex < maxIndex)
        {
                heap_t *current = file[currentIndex++];

                /* If current node has one NULL child -> return node */
                if (!current->left || !current->right)
                        return (current);

                /* else Add children to the file */
                file[maxIndex++] = current->left;
                file[maxIndex++] = current->right;
        }

        return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: pointer to root of the binary tree
 * @value: integer number to  insert at the binary tree
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *newNode;
	heap_t temp;

	// Find the parent node to insert child
	parent = find_insertion_parent(*root);

	// add a new node to the parent founded
	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = newNode;
	else
		parent->right = newNode;

	// while newNode is not to the right place, swap with parent
	while (newNode->parent != NULL)
	{
		if (newNode->parent->n < value)
		{
			temp = *newNode->parent;
			*newNode->parent = *newNode;
			*newNode = temp;
		}
		else
		{
			break;
		}
	}

	return (newNode);
}

