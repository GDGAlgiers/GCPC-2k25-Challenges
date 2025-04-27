#include <stdio.h>
#include <stdbool.h>

// Size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if placing num in board[row][col] is valid
bool isValid(int board[N][N], int row, int col, int num) {
    // Check if the number exists in the row
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check if the number exists in the column
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check if the number exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku board using Backtracking
bool solveSudoku(int board[N][N]) {
    int row, col;
    bool empty = false;

    // Find an empty space on the board
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) {
            break;
        }
    }

    // If there are no empty spaces left, we are done
    if (!empty) {
        return true;
    }

    // Try all numbers from 1 to 9
    for (int num = 1; num <= N; num++) {
        if (isValid(board, row, col, num)) {
            // Place the number in the empty space
            board[row][col] = num;

            // Recursively attempt to solve the board
            if (solveSudoku(board)) {
                return true;
            }

            // If placing num didn't work, backtrack and try the next number
            board[row][col] = 0;
        }
    }
    return false;
}
bool isBoardValid(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] != 0) {  // Only check non-empty cells
                int num = board[row][col];
                // Temporarily remove the number to check for validity
                board[row][col] = 0;
                if (!isValid(board, row, col, num)) {
                    return false;
                }
                // Restore the number
                board[row][col] = num;
            }
        }
    }
    return true;
}
int main() {
    int board[N][N];
;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

   if (!isBoardValid(board)) {
        printf("-1");
        return 0;
    }

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        printf("-1");
    }

    return 0;
}
