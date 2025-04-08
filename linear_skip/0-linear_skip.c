#include "search.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 * Return: Pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list;
	skiplist_t *express_node = NULL;

	if (!list)
		return (NULL);

	/* Traverse the skip list using the express lane */
	while (node->express)
	{
		express_node = node->express;
		/* Print the current node value */
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (express_node->n >= value)
		{
			break;
		}
		node = express_node;
	}
	/* Print the range we're searching between */
	printf("Value found between indexes [%lu] and [%lu]\n"\
	, node->index, express_node->index);
	/* Perform linear search within the range between node and express_node */
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		if (node == express_node)
			break;
		node = node->next;
	}
	return (NULL);
}

