#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"


/**
 * draw_sponge - Recursively draws a Menger Sponge.
 * @level: The current level of the sponge.
 * @size: The total size of the grid at the current level.
 * @sponge: Pointer of the sponge to draw
 */
static void draw_sponge(int level, int size, char **sponge)
{
	if (level == 0)
	{
		sponge[0][0] = '#';
		return;
	}
	int small_size = size / 3;
	char **small_sponge = (char **)malloc(small_size * sizeof(char *));

	for (int i = 0; i < small_size; i++)
		small_sponge[i] = (char *)malloc(small_size * sizeof(char));
	draw_sponge(level - 1, small_size, small_sponge);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i / small_size == 1) && (j / small_size == 1))
				sponge[i][j] = ' ';
			else
			{
				int x = i % small_size;
				int y = j % small_size;

				sponge[i][j] = small_sponge[x][y];
			}
		}
	}
	for (int i = 0; i < small_size; i++)
		free(small_sponge[i]);
	free(small_sponge);
}

/**
 * menger - Draws the full Menger Sponge for the given level.
 * @level: The level of the Menger Sponge to draw.
 */
void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);
	char **sponge = (char **)malloc(size * sizeof(char *));

	for (int i = 0; i < size; i++)
		sponge[i] = (char *)malloc(size * sizeof(char));
	draw_sponge(level, size, sponge);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%c", sponge[i][j]);
		printf("\n");
	}
	for (int i = 0; i < size; i++)
		free(sponge[i]);
	free(sponge);
}

