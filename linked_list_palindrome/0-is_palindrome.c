#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to list
 * Return: 1 if the list is a palindrome, other wise return 0.
 */
int is_palindrome(listint_t **head)
{
	int nbInt = 0;
	listint_t *current;

	current = *head;
	if (*head == NULL)
		return (1);
	nbInt = 1;
	while (current->next != NULL)
	{
		nbInt += 1;
		current = current->next;
	}

	int list[nbInt];
	int reverseList[nbInt];
	int currentInt = 0;
	int reverseInt = nbInt - 1;

	current = *head;
	list[currentInt] = current->n;
	reverseList[reverseInt] = current->n;
	while (current->next != NULL)
	{
		current = current->next;
		currentInt += 1;
		reverseInt -= 1;
		list[currentInt] = current->n;
		reverseList[reverseInt] = current->n;
	}
	for (int i = 0; i < nbInt; i++)
	{
		if (list[i] != reverseList[i])
			return (0);
	}
	return (1);
}

