#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node
 * @parent: pointer to parent the binary tree
 * @value: integer number to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tmpNode;
	binary_tree_t *tmpTree = parent;
	binary_tree_t *elem = malloc(sizeof(binary_tree_t));

	if (elem == NULL)
		return (NULL);

	elem->n = value;
	elem->parent = parent;
	elem->left = NULL;
	elem->right = NULL;

	if (tmpTree)
	{
		do
		{
			tmpNode = tmpTree;
			if (value > tmpTree->n)
			{
				tmpTree = tmpTree->right;
				if (!tmpTree)
					tmpNode->right = elem;
			}
			else
			{
				tmpTree = tmpTree->left;
				if (!tmpTree)
					tmpNode->left = elem;
			}
		} while (tmpTree);
	
	}
	else
		parent = elem;

	return (elem);
}

