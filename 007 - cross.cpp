/* Wenbin Wu
Lab 21D
Assignment #7 eight numbers in a cross problem
*/

#include <iostream>
#include <cmath>
using namespace std;

void printCross(int arr[]) {
    cout << "\t" << arr[1] << "\t" << arr[4] << "\t" << endl;
    cout << arr[0] << "\t" << arr[2] << "\t" << arr[5] << "\t" << arr[7] << "\t" << endl;
    cout << "\t" << arr[3] << "\t" << arr[6] << "\t" << endl;
    cout << endl;
}

bool isNumOK(int arr[], int indices[], int num) {  // tests if a number is valid to place on cross
    for (int i = 0; i < 8; i++) {  // if the number is already used, return false
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

int main() {
    int numArray[8] = {0};
    int helperArray[8][5] = {
                    {-1},
                    {0, -1},
                    {0, 1, -1},
                    {0, 2, -1},
                    {1, 2, -1},
                    {1, 2, 3, 4, -1},
                    {2, 3, 5, -1},
                    {4, 5, 6, -1},
                    };

    int position = 0, num = 1;

    while(position >= 0) {
        if (position == 8 || num > 8) {  // backtrack
            position--;
            if (position < 0) {
                return 0;
            }
            num = numArray[position];
            numArray[position] = 0;
            num++;
            continue;
        }

        if (isNumOK(numArray, helperArray[position], num)) {
            numArray[position] = num; // if a number is good, place it on the cross
            num = 1;
            position++;
            if (position == 8) {
                cout << "Solution: " << endl;
                printCross(numArray); // print the cross if all positions are filled
            }
        }
        else {  // go to next number
            num++;
        }
    }
}