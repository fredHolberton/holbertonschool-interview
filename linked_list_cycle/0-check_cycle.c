#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to list to be checked
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *current = list;
	listint_t *next = list;
		
	while (next != NULL && next->next != NULL)
	{
		current = current->next;
		next = next->next->next;
		if (current == next)
			return (1);
	}
	return (0);
}

