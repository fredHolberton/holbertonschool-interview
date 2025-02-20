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
	if (list == NULL)
		return (0);
	else
	{
		
		int file[1024];
		listint_t *current;
		int nbElt = 0;

		current = list;
		while (current->next != NULL)
		{
			for (int i = 0; i < nbElt; i++)
			{
				if (file[i] == current->next->n)
					return (1);
			}
			file[nbElt] = current->next->n;
			current = current->next;
			nbElt += 1;
		}
	}
	return (0);
}

