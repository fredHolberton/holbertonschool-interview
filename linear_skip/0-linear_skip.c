#include "search.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 * Return: Pointer on the first node where value is located, NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express;
	size_t indexMax;
	const char msg1[37] = "Value checked at index [%lu] = [%d]\n";
	const char msg2[45] = "Value found between indexes [%lu] and [%lu]\n";

	if (list == NULL)
		return (NULL);
	current = list;
	express = list->express;
	while (current->next != NULL)
		current = current->next;
	indexMax = current->index;
	current = list;
	while (express != NULL && express->n < value)
	{
		printf(msg1, express->index, express->n);
		current = express;
		express = express->express;
	}
	if (express != NULL)
	{
		printf(msg1, express->index, express->n);
		printf(msg2, current->index, express->index);
	}
	else
	{
		printf(msg2, current->index, indexMax);
	}
	while (current != NULL && current->n <= value)
	{
		printf(msg1, current->index, current->n);
		if (current->n == value)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

