#include "binary_trees.h"
#include <limits.h>

/**
 * max - Return the maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: the maximum
 */
static int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or -1 if tree is NULL
 */
static int tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);
	return (1 + max(tree_height(tree->left), tree_height(tree->right)));
}

/**
 * is_avl_helper - Checks if a tree is a valid AVL Tree
 * @tree: pointer to the root node
 * @min: minimum valid value for current subtree
 * @max: maximum valid value for current subtree
 * Return: 1 if tree is AVL, 0 otherwise
 */
static int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int lh, rh, balance;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	lh = tree_height(tree->left);
	rh = tree_height(tree->right);
	balance = lh - rh;

	if (balance > 1 || balance < -1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node
 * Return: 1 if tree is AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		 return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
