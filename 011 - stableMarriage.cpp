/*
Wenbin Wu
CS211 21D
Assignment 11 - Stable marriage using backtracking
*/

#include <iostream>
using namespace std;

void printMarriages(int arr[]) {  // print out the solution
    for (int i = 0; i < 3; i++) {
        cout << arr[i];
    }
    cout << endl;
}

int isOK(int arr[], int col, int w) {  // tests a new woman assignment to new man
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

int main() {
    int marriages[3] = {0};
    int col = 0, w = 0;  // w = new woman assigned to the man (col) 

    while (col >= 0) {
        if (col == 3 || w == 3) {  // backtrack
            col--;
            if (col < 0) {
                return 0;
            }
            w = marriages[col];
            marriages[col] = 0;
            w++;
            continue;
        }

        if (isOK(marriages, col, w)) {
            marriages[col] = w;  // if new woman passed isOK tests, assign to the new man
            w = 0;
            col++;
            if (col == 3) {  // if the entire array is filled, print out the solution
                printMarriages(marriages);
            }
        }
        else {
            w++;
        }
    }
}