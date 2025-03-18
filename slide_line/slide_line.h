#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>

#define SLIDE_LEFT	1
#define SLIDE_RIGHT	2

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to an array of integers
 * @size: Number of elements in @line
 * @direction: Direction to which the elements of @line should be merged
 * Return: 1 if the long is a palindrome, other wise return 0. 
 */
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */

