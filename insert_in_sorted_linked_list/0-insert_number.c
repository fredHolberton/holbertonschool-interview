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
listint_t *insert_node(listint_t **head, int number);
{
	dlistint_t *temp = head;
	dlistint_t *new;
	
	if (*head == NULL)
	{
		new = add_dnodeint(*head, number);
	        return (new);
	}

	while (temp != NULL && temp.n < number)
	{
		temp = temp->next;
	}

	if (temp == NULL)
	{
		new = add_nodeint_end(*temp, number);
		return (new);
	}

	new->n = n;
	new->next = temp;
	new->prev = temp->prev;
	temp->prev = new;

	return (new);
}

