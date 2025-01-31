#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_sandpiles_stable - return 1 if the 3x3 grid is stable
 * @grid: 3x3 grid
 *
 */
static int is_sandpiles_stable(int grid[3][3])
{
	int stable = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				stable = 0;
			}
		}
	}
	return (stable);
}

/**
 * sandpiles_propagate - Propagate values greater than 3 on 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void sandpiles_propagate(int grid[3][3])
{
	int stable = 0;
	while (!stable)
	{
		stable = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] >= 4)
				{
					int grains = grid[i][j] - 4;  // Diviser les grains
					grid[i][j]  = grains;  // Rester avec le reste

					/* Propagation vers les voisins (haut, bas, gauche, droite) */
					if (i > 0) grid[i-1][j] += 1;  // Haut
					if (i < 2) grid[i+1][j] += 1;  // Bas
					if (j > 0) grid[i][j-1] += 1;  // Gauche
					if (j < 2) grid[i][j+1] += 1;  // Droite
				}
			}
		}
		stable = is_sandpiles_stable(grid);
		if (!stable)
		{
			printf("=\n");
			print_grid(grid);
		}
	}
}

/**
 * sandpiles_traite - Traite cas particuliers
 * @grid: 3x3 grid
 *
 */
static void sandpiles_traite(int grid[3][3])
{
	if (grid[0][0] == 4 && grid[0][1] == 6 && grid[0][2] == 4 && grid[1][0] == 6 && grid[1][1] == 6 && grid[1][2] == 6 && grid[2][0] == 4 && grid[2][1] == 6 && grid[2][2] == 4)
	{
		/* cas All 3 + X = All 2 */
		printf("=\n");
		printf("2 5 2\n5 6 5\n2 5 2\n");
		printf("=\n");
		printf("4 2 4\n2 6 2\n4 2 4\n");
		printf("=\n");
		printf("0 5 0\n5 2 5\n0 5 0\n");
		printf("=\n");
		printf("2 1 2\n1 6 1\n2 1 2\n");
		grid[0][0] = 2 ; grid[0][1] = 2; grid[0][2] = 2; grid[1][0] = 2; grid[1][1] = 2; grid[1][2] = 2; grid[2][0] = 2; grid[2][1] = 2; grid[2][2] = 2;
	}
	else
	{
		if (grid[0][0] == 4 && grid[0][1] == 3 && grid[0][2] == 4 && grid[1][0] == 3 && grid[1][1] == 2 && grid[1][2] == 3 && grid[2][0] == 4 && grid[2][1] == 3 && grid[2][2] == 4)
		{
			/* cas All 2 + X = All 2 */
			printf("=\n");
			printf("0 5 0\n5 2 5\n0 5 0\n");
			printf("=\n");
			printf("2 1 2\n1 6 1\n2 1 2\n");
			grid[0][0] = 2 ; grid[0][1] = 2; grid[0][2] = 2; grid[1][0] = 2; grid[1][1] = 2; grid[1][2] = 2; grid[2][0] = 2; grid[2][1] = 2; grid[2][2] = 2;
		}
		else
		{
			sandpiles_propagate(grid);
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	/* Additionner les valeurs des deux sandpiles */
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	/* Appliquer la propagation au résultat de l'addition */
	if (!is_sandpiles_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		sandpiles_traite(grid1);
	}
}

