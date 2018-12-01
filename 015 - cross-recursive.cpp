/* 
Wenbin Wu
CS211 21D
Assignment 15 - Recursive Cross
*/

#include <iostream>
#include <cmath>
using namespace std;

void print(int* arr) {
    cout << "\t" << arr[1] << "\t" << arr[4] << "\t" << endl;
    cout << arr[0] << "\t" << arr[2] << "\t" << arr[5] << "\t" << arr[7] << "\t" << endl;
    cout << "\t" << arr[3] << "\t" << arr[6] << "\t" << endl;
    cout << endl;
}

bool ok(int* arr, int position, int indices[], int num) {  // tests if a number is valid to place on cross
    for (int i = 0; i < position; i++) {  // if the number is already used, return false
        if (arr[i] == num)
            return false;
    }

    int i = 0;
    while (indices[i] != -1) {  // check adjacent positions for consecutive numbers
        int index = indices[i];
        int absValue = abs(arr[index] - num);
        if (absValue <= 1)
            return false;
        i++;
    }
    return true;
}

void move(int* n, int position, int num) {
    static int helperArray[8][5] = {
        {-1},
        {0, -1},
        {0, 1, -1},
        {0, 2, -1},
        {1, 2, -1},
        {1, 2, 3, 4, -1},
        {2, 3, 5, -1},
        {4, 5, 6, -1},
    };
    
    if (position == 8) {
        print(n); // print the cross if all positions are filled
        return;
    }

    for (int j = 1; j <= 8; j++) {
        n[position] = j;
        if (ok(n, position, helperArray[position], j))
            move(n, position + 1, j);
    }
}

int main() {
    int numArray[8] = {0};
    int position = 0;
    move(numArray, position, 1);
}