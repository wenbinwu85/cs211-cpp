/*Wenbin Wu
Lab 21D
Assignment #9 fancy output for n-queens, windows version
*/

#include <iostream>
using namespace std;

void fancyBoardPrint(int queens[], int size) {
    int i, j, k, l;
    typedef wchar_t box[5][7]; 
    box bb, wb, bq, wq, *board[size][size];

    for(i = 0; i < 5; i++) {  //fill in bb = full block char and wb = empty space
        for( j = 0; j < 7; j++) {
            wb[i][j] = ' ';
            bb[i][j] = wchar_t(219);
        }
    }

    for(i = 0; i < 5; i++) {  //fill in queen blocks
        for( j = 0; j < 7; j++) {
            if (i == 0 || i == 4) {
                wq[i][j] = ' ';
                bq[i][j] = wchar_t(219);
            }
            else if (j == 0 || j == 6) {
                wq[i][j] = ' ';
                bq[i][j] = wchar_t(219);
            }
            else if (i == 1 && (j == 2 || j == 4)) {
                wq[i][j] = ' ';
                bq[i][j] = wchar_t(219);
            }
            else {
                wq[i][j] = wchar_t(219);
                bq[i][j] = ' ';
            }
        }
    }

    //fill board with pointers to bb and wb in alternate positions 
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if((i + j) % 2 == 0) {
                if (queens[i] == j)
                    board[i][j] = &wq;
                else
                    board[i][j] = &wb;
            }
            else {
                if (queens[i] == j)
                    board[i][j] = &bq;
                else
                    board[i][j] = &bb;
            }
        }
    }

    // print the board via the pointers in array board
    // first print upper border 
    cout << " "; 
    for(i = 0; i < 7 * size; i++)
        cout << '_'; 
    cout << endl;

    // now print the board 
    for(i = 0; i < size; i++) {
        for(k = 0; k < 5; k++) {
            cout << ' ' << char (179);
            for (j = 0; j < size; j++) {
                for(l = 0; l < 7; l++) 
                    wcout << wchar_t((*board[i][j])[k][l]);
            }
            cout << char(179) << endl;
        }
    }

    //before exiting print lower border 
    cout << " ";
        for(i = 0; i < 7 * size + 4; i++)
            cout << char(196);
    cout << endl;
}

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

int main() {
    int size = 8, row = 0, col = 0, solution = 0;
    int queens[8] = {0};  // index  = column, value = row 

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
                fancyBoardPrint(queens, size);
                cout << endl;
            }
        }
        else {
            row++;
        }
    }
}