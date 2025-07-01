#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list);

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: Pointer to the pointer of the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str);

/**
 * add_node_begin - Adds a new node to the beginning of the linked list
 * @list: Pointer to the pointer of the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
