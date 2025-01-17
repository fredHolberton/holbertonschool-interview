#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree);

/**
 * binary_tree_node - Create a binary tree node
 * @parent: pointer to parent the binary tree
 * @value: integer number to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/**
 * find_insertion_parent - Finds the insertion parent in a Max binary Heap
 * @root: Pointer to the root node
 *
 * Return: Pointer to the parent where the new node should be inserted
 */
heap_t *find_insertion_parent(heap_t *root);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: pointer to root of the binary tree
 * @value: integer number to  insert at the binary tree
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value);

#endif /* _BINARY_TREES_H_ */
