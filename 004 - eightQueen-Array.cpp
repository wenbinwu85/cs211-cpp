// Wu wenbin
// Lab 21D
// 8-Queen problem solver using 1d array and backtrack

#include <iostream>

using namespace std;

int main() {
    int queens[8] = {0};  // index  = column, value = row 
    int size = 8, row = 0, col = 0, solution = 0;

tests:
    for (int c = 0; c < col; c++) { // horizontal test
        if (row == queens[c])
            goto next_row;
    }

    for (int i = 1; row - i >= 0 && col - i >= 0; i++) { // up diagonal test
        if (row - i == queens[col - i])
            goto next_row;
    }

    for (int i = 1; row + i < size && col - i >= 0; i++) {  // down diagonal test
        if (row + i == queens[col - i])
            goto next_row;
    }

    queens[col] = row;  // place a queen
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
        goto print_queens;
    goto tests;

print_queens:
    solution++;
    cout << "Solution # " << solution << endl;  
    for (int i = 0; i < size; i++) { // print the solution out
        for (int j = 0; j < size; j++) {
            if (queens[j] == i)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;

backtrack:
    col--; // goes back to previous column
    if (col < 0) {
        cout << "Number of solutions found: " << solution << endl;
        return 0;
    }
    row = queens[col];  // row check will continue from last queen row position
    queens[col] = 0;  // clear queen from current column
    goto next_row;  // continue checking the next row
}