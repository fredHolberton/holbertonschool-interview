#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * slide_line_to_left - Slides and merges an array of integers to left
 * @line: Pointer to an array of integers
 * @size: Number of elements in @line
 */ 
static void slide_line_to_left(int *line, size_t size)
{
	size_t i = 0;
	for (size_t j = 1; j < size; j++)
	{
		if (line[j] != 0)
		{
			if (line[i] == 0)
			{
				line[i] = line[j];
				line[j] = 0;
			}
			else if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
				i++;
			}
			else
			{
				i++;
				if (i != j)
				{
					line[i] = line[j];
					line[j] = 0;
				}
			}
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to an array of integers
 * @size: Number of elements in @line
 * @direction: Direction to which the elements of @line should be merged
 * Return: 1 if the long is a palindrome, other wise return 0.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size == 0 || (direction != 1 && direction != 2))
	{
		return 0;
	}
	if (direction == 2)
	{
		int temp;
		for (size_t i = 0; i < size / 2; i++)
		{
			temp = line[i];
			line[i] = line[size - 1 - i];
			line[size - 1 - i] = temp;
		}
	}
	slide_line_to_left(line, size);
	if (direction == 2)
	{
		int temp;
		for (size_t i = 0; i < size / 2; i++)
		{
			temp = line[i];
			line[i] = line[size - 1 - i];
			line[size - 1 - i] = temp;
		}
	}
	return 1;
}

