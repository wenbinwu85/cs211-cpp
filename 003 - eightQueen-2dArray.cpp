// Wu Wenbin
// Lab 21D
// 8-Queen problem solver using 2d array and backtrack

#include <iostream>

using namespace std;

int main() {
    int board[8][8] = {0};
    int size = 8, row = 0, col = 0, solution = 0;

tests:
    for (int c = 0; c < col; c++) {  // horizontal test
        if (board[row][c] == 1)
            goto next_row;
    }

    for (int i = 1; row - i >= 0 && col - i >= 0; i++) {  // up diagonal test
        if (board[row - i][col - i] == 1)
            goto next_row;
    }

    for (int i = 1; row + i < size && col - i >= 0; i++) {  // down diagonal test
        if (board[row + i][col - i] == 1)
            goto next_row;
    }

    board[row][col] = 1;  // place queen at current row/col
    row = 0;
    goto next_column;

next_row:
    row++;
    if (row == size)
        goto backtrack;
    goto tests;

next_column:
    col++;
    if (col == size)
        goto print_board;
    goto tests;

print_board:
    solution++;
    cout << "Solution # " << solution << endl;  // print the solution out
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;

backtrack:
    col--;  // goes back to previous column
    if (col < 0) {
        cout << "Number of solutions found: " << solution << endl;
        return 0;  // exits the program when all solutions are found
    }
    row = 0;
    while (board[row][col] == 0)
        row++;
    board[row][col] = 0;
    goto next_row;
}