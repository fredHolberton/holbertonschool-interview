#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Args:
        grid (list of list of int): 0 represents water, 1 represents land

    Returns:
        int: the perimeter of the island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Assume 4 sides
                perimeter += 4

                # If there is a land cell above, subtract 2 (shared edge)
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

                # If there is a land cell on the left, subtract 2 (shared edge)
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
