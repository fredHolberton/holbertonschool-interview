#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
void binary_tree_print(const binary_tree_t *);

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Number of nodes
 */
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * get_last_node - Finds the last node in a binary heap (level-order)
 * @root: Pointer to the root node
 * @index: Current index (used in recursion)
 * @target: Index of the node to find
 * Return: Pointer to the node or NULL
 */
binary_tree_t *get_last_node(binary_tree_t *root, size_t index, size_t target);

/**
 * heapify_down - Restores Max Heap property by sifting down
 * @root: Pointer to the root node
 */
void heapify_down(heap_t *root);

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H */
