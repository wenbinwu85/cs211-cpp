/*
/ Wu Wenbin
/ Lab 21D
/ dumb 8-Queen problem with 2d array and backtrack
*/

#include <iostream>
using namespace std;

bool ok(int board[][8]) {
    for(int col = 0; col < 8; col++) {
        int row = 0;
        
        while(board[row][col] != 1)
            row++;

        for(int c = 0; c < col; c++) {  // horizontal test
            if(board[row][c] == 1)
                return false;
        }

        for(int i = 1; row - i >= 0 && col - i >= 0; i++) {  // up diagonal test
            if(board[row - i][col - i] == 1)
                return false;
        }

        for(int i = 1; row + i < 8 && col - i >= 0; i++) {  // down diagonal test
            if(board[row + i][col - i] == 1) 
                return false;
        }
    }
    return true;
}

void print(int board[8][8], int count) {
    cout << count << endl;
    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            cout << board[i][j];
        cout << endl;
    }
    cout << endl;
}

int main () {
    int board[8][8] = {0};
    int count = 0;

    for(int i0 = 0; i0 < 8; i0++)
        for(int i1 = 0; i1 < 8; i1++)
            for(int i2 = 0; i2 < 8; i2++)
                for(int i3 = 0; i3 < 8; i3++)
                    for(int i4 = 0; i4 < 8; i4++)
                        for(int i5 = 0; i5 < 8; i5++)
                            for(int i6 = 0; i6 < 8; i6++)
                                for(int i7 = 0; i7 < 8; i7++) {
                                    board[i0][0] = 1;
                                    board[i1][1] = 1;
                                    board[i2][2] = 1;
                                    board[i3][3] = 1;
                                    board[i4][4] = 1;
                                    board[i5][5] = 1;
                                    board[i6][6] = 1;
                                    board[i7][7] = 1;

                                    if(ok(board))
                                        print(board, ++count);

                                    board[i0][0] = 0;
                                    board[i1][1] = 0;
                                    board[i2][2] = 0;
                                    board[i3][3] = 0;
                                    board[i4][4] = 0;
                                    board[i5][5] = 0;
                                    board[i6][6] = 0;
                                    board[i7][7] = 0;
                                }
    return 0;
}