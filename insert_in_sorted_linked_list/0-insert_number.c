#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: integer number to insert
 *
 * Return: address of the new node, or null if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *temp = *head;
	listint_t *new;
	
	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		if (temp->n > number)
		{
			new->next = temp;
			*head = new;
		}
		else
		{
			while (temp->next != NULL && temp->next->n < number)
		 	{	
				temp = temp->next;
			}	

			if (temp->next == NULL)
			{
				new->next = NULL;
			}
			else
			{
				new->next = temp->next;
			}
			
			temp->next = new;
		}
	}

	return (new);
}

