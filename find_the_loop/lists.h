#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/**                                                                                                                                                                            
 * add_nodeint - add a node and return the adress of it.                                                                                                                
 * @head: Pointer to the head of the list.
 * @n: Integer to be added.
 *
 * Return: Address of the new node.
 */
listint_t *add_nodeint(listint_t **head, const int n);

/**
 * print_listint_safe - Print the linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: size_t.
 */
size_t print_listint_safe(const listint_t *head);

/**
 * free_listint_safe - free the linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: size_t.
 */
size_t free_listint_safe(listint_t **h);

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head);

#endif /* _LISTS_H */
