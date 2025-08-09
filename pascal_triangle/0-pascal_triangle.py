#!/usr/bin/python3
def pascal_triangle(n):
    """
    Returns a list of lists of integers representing Pascal's triangle of n.
    Returns an empty list if n <= 0
    """
    if n <= 0:
        return []

    triangle = [[1]]  # First row

    for i in range(1, n):
        prev_row = triangle[-1]
        # Each new row starts and ends with 1
        row = [1]
        # Fill the middle values
        for j in range(1, len(prev_row)):
            row.append(prev_row[j - 1] + prev_row[j])
        row.append(1)
        triangle.append(row)

    return triangle
