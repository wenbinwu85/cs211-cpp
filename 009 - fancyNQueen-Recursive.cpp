#include <iostream>

using namespace std;

bool ok(int* q, int i) {
    for (int k = 0; k < i; k++) {
        if ((q[k] == q[i]) || (abs(q[k] - q[i]) == i - k))
            return false;
    }
    return true;
}

void fancyPrint(int* queens, int size) {
    int i, j, k, l;
    typedef string box[5][7]; 
    box bb, wb, bq, wq, *board[size][size];

    for(i = 0; i < 5; i++) {  //fill in bb = full block char and wb = empty space
        for( j = 0; j < 7; j++) {
            wb[i][j] = " ";
            bb[i][j] = "█";
        }
    }

    for(i = 0; i < 5; i++) {  //fill in queen blocks
        for( j = 0; j < 7; j++) {
            if (i == 0 || i == 4) {
                wq[i][j] = " ";
                bq[i][j] = "█";
            }
            else if (j == 0 || j == 6) {
                wq[i][j] = " ";
                bq[i][j] = "█";
            }
            else if (i == 1 && (j == 2 || j == 4)) {
                wq[i][j] = " ";
                bq[i][j] = "█";
            }
            else {
                wq[i][j] = "█";
                bq[i][j] = " ";
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
            cout << ' ' << "│";
            for (j = 0; j < size; j++) {
                for(l = 0; l < 7; l++) 
                    cout << (*board[i][j])[k][l];
            }
            cout << "│" << endl;
        }
    }

    //before exiting print lower border 
    cout << " ";
        for(i = 0; i < 7 * size + 4; i++)
            cout << "─";
    cout << endl;
}

void move(int* q, int size, int i) {
    if (i == size) {
        fancyPrint(q, size);
        return;
    }
    for (int j = 0; j < size; j++) {
        q[i] = j;
        if (ok(q, i))
            move(q, size, i + 1);
    }
}

int main() {
    int size = 8;
    int q[size];
    move(q, size, 0);
}