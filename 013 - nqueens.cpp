/*
Wenbin Wu
Lab 21D
Assignment #13 n-queens problem
*/

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

void findSolutions(int size) {
	int	row = 0, col = 0, solution = 0;
	int* queens = new int[size];

	while (col >= 0) {
        if (col == size || row == size)
        {
            col--; // goes back to previous column
            if (col < 0) {
                cout << "There are " << solution << " solutions to the " << size << " problem." << endl;
                delete []queens;
                break;
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
            if (col == size)
                solution++;
        }
        else
            row++;
    }

}

int main() {
    int size;
	cout << "Enter size: ";
	cin >> size;

    for (int i = 1; i <= size; i++)
        findSolutions(i);
}