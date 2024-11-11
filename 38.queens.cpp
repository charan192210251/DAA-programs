#include <stdio.h>
#include <stdlib.h>  // For abs()

// Function to print the board with queens placed on it
void printSolution(int board[], int N) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                printf(" Q ");  // Queen is placed at [i, j]
            } else {
                printf(" * ");  // Empty space
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at [row, col]
int isSafe(int board[], int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;  // Conflict with another queen
        }
    }
    return 1;  // No conflict
}

// Backtracking function to solve the N-Queens problem
int solveNQueens(int board[], int row, int N) {
    if (row == N) {
        // All queens are placed successfully, print the solution
        printSolution(board, N);
        return 1;  // Return true after finding the first solution
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row] = col;  // Place queen at [row, col]
            if (solveNQueens(board, row + 1, N)) {
                return 1;  // Stop after finding the first solution
            }
        }
    }
    return 0;  // No solution found
}

int main() {
    int N;

    // Input the number of queens (size of the board)
    printf("Enter the number of queens: ");
    scanf("%d", &N);

    // Initialize the board
    int board[N];
    for (int i = 0; i < N; i++) {
        board[i] = -1;  // No queens placed initially
    }

    // Solve the N-Queens problem
    if (!solveNQueens(board, 0, N)) {
        printf("No solution exists for %d queens.\n", N);
    }

    return 0;
}

