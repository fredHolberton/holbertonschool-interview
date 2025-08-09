#!/usr/bin/python3
""" Module : pascal_triangle """

def pascal_triangle(n):
    """ Return a list of lists of integer like Pascal's triangle of n """

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
