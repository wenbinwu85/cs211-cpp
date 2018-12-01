/*
Wenbin Wu
CS211 21D
Assignment 17 - shortestPath bottom-up
*/

#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int memo[rows][cols];  // memoize the direction of min path form previous column

int cost(int i, int j) {
    int weight[rows][cols] = {
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 8, 6, 4}};

    if (j == 0) {
        return weight[i][j];
    }

    // recursive calls
    int up = cost((i + 4) % rows, j - 1);
    int left = cost(i, j - 1);
    int down = cost((i + 1) % rows, j - 1);

    // find the value of the shortest path through cell (i, j)
    int min = up;
    memo[i][j] = -1;  
    // memoize the direction of previous min path -1 = up, 0 = left, 1 = down
    if (left < min) {
        min = left;
        memo[i][j] = 0;
    }

    if (down < min) {
        min = down;
        memo[i][j] = 1;
    }
    return weight[i][j] + min;
}

int main() {
    int ex[rows];
    // get the shortest path out of each cell on the right
    for (int i = 0; i < rows; i++) {
        ex[i] = cost(i, cols-1);
    }

    // now find the sallest of them
    int shortestRow;
    int min = ex[0];
    for (int i = 1; i < rows; i++) {
        if (ex[i] < min) {
            min = ex[i];
            shortestRow = i;
        }
    }

    int shortestPath[cols] = {0};  // put the rows with the min cost
    for (int c = cols - 1; c >= 0; c--) {
        shortestPath[c] = shortestRow + 1;
        shortestRow = (shortestRow + memo[shortestRow][c]) % rows;
    }

    cout << "Rows to choose: ";
    for (int c = 0; c < cols; c++)  // print the shortest path in left to right order
        cout << shortestPath[c] << " ";
    cout << endl;
    cout << "The shortest path is of length: " << min << endl;
    return 0;
}