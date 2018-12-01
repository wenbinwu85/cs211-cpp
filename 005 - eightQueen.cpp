// Wu wenbin
// Lab 21D
// 8-Queen problem solver using 1d array, no goto statements

#include <iostream>

using namespace std;

bool tests(int queens[], int size, int row, int col) {
    for (int c = 0; c < col; c++) { // horizontal test
        if (row == queens[c])
            return false;
    }

    for (int i = 1; row - i >= 0 && col - i >= 0; i++) { // up diagonal test
        if (row - i == queens[col - i])
            return false;
    }

    for (int i = 1; row + i < size && col - i >= 0; i++) {  // down diagonal test
        if (row + i == queens[col - i])
            return false;
    }
    return true;
}

void printBoard(int queens[], int size) {  // print the solution out
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) {
            if (queens[j] == i)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    int queens[8] = {0};  // index  = column, value = row 
    int size = 8, row = 0, col = 0, solution = 0;

    while (col >= 0) {
        if (col == size || row == size) {
            col--; // goes back to previous column
            if (col < 0) {
                cout << "Number of solutions found: " << solution << endl;
                return 0;
            }
            row = queens[col];  // row check will continue from last queen row position
            queens[col] = 0;  // clear queen from current column
            row++;
            continue; // continue checking the next row
        }

        if (tests(queens, size, row, col)) {
            queens[col] = row;  // place a queen
            row = 0;
            col++;
            if (col == size) {
                solution++;
                cout << "Solution # " << solution << endl;
                printBoard(queens, size);
            }
        }
        else {
            row++;
        }
    }
}