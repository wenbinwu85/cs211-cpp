/*
Wenbin Wu
CS211 21D
Assignment 17 - shortestPath top-down
*/

#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int memoDir[rows][cols];  // memoize the direction of min path form previous column
int memoCost[rows][cols];  // memoize cost to get to each cell

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
    int up = memoCost[(i + 4) % rows][j - 1];
    int left = memoCost[i][j - 1];
    int down = memoCost[(i + 1) % rows][j - 1];

    // find the value of the shortest path through cell (i, j)
    int min = up;
    memoDir[i][j] = -1;  
    // memoize the direction of previous min path -1 = up, 0 = left, 1 = down
    if (left < min) {
        min = left;
        memoDir[i][j] = 0;
    }
 
    if (down < min) {
        min = down;
        memoDir[i][j] = 1;
    }

    return weight[i][j] + min;
}

int main() {
    // get the shortest path out of each cell from the left
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
           memoCost[i][j] = cost(i, j);  // memoize to cost to get to each cell
        }
    }

    // now find the sallest of them
    int shortestRow;
    int min = memoCost[0][cols - 1];
    for (int i = 1; i < rows; i++) {
        if (memoCost[i][cols-1] < min) {
            min = memoCost[i][cols-1];
            shortestRow = i;
        }
    }

    int shortestPath[cols] = {0};  // array to put the rows with the min cost
    for (int c = cols - 1; c >= 0; c--) {
        shortestPath[c] = shortestRow + 1;
        shortestRow = (shortestRow + memoDir[shortestRow][c]) % rows;
    }

    cout << "Rows to choose: ";
    for (int c = 0; c < cols; c++)  // print the shortest path in left to right order
        cout << shortestPath[c] << " ";
    cout << endl;
    cout << "The shortest path is of length: " << min << endl;
    return 0;
}