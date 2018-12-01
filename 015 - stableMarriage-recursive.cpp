/*
Wenbin Wu
CS211 21D
Assignment 15 - Recursive Stable marriage
*/

#include <iostream>
using namespace std;

void print(int* arr) {  // print out the solution
    for (int i = 0; i < 3; i++) {
        cout << arr[i];
    }
    cout << endl;
}

bool ok(int* arr, int col, int w) {  // tests a new woman assignment to new man
    int mp[3][3]={  // men preferences
        {0, 2, 1}, 
        {0, 2, 1}, 
        {1, 2, 0}};

    int wp[3][3]={  // women preferences
        {2, 1, 0}, 
        {0, 1, 2}, 
        {2, 0, 1}};

    for (int i = 0; i < col; i++) {  // if stable marriage conditions not met, this assignment is no good
        if (arr[i] == w)
            return false;
        if (mp[i][w] < mp[i][arr[i]] && wp[w][i] < wp[w][col])
            return false;
        if (wp[arr[i]][col] < wp[arr[i]][i] && mp[col][arr[i]] < mp[col][w])
            return false;
    }
    
    return true;
}

void move(int* m, int col, int i) {
    if (col == 3) {
        print(m);
        return;
    }

    for (int j = 0; j < 3; j++) {
        m[col] = j;
        if (ok(m, col, j))
            move(m, col + 1, j);
    }
}

int main() {
    int marriages[3] = {0};
    int col = 0;
    move(marriages, col, 0);
}