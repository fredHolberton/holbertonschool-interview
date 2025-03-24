#!/usr/bin/python3
""" Module : N Queens """


import sys

def print_solution(board):
    """Print a single solution in the form of coordinates."""
    solution = []
    for row, col in enumerate(board):
        solution.append([row, col])
    print(solution)

def is_safe(board, row, col):
    """Check if it's safe to place a queen at (row, col)."""
    for i in range(row):
        # Check if the queen is in the same column or diagonal
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True

def solve_nqueens(board, row, N):
    """Recursively solve the N queens problem."""
    if row == N:
        print_solution(board)
        return

    for col in range(N):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(board, row + 1, N)
            board[row] = -1  # Backtrack

def main():
    """Main function to read input and solve the N queens problem."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialize the board
    board = [-1] * N
    solve_nqueens(board, 0, N)

if __name__ == "__main__":
    main()
