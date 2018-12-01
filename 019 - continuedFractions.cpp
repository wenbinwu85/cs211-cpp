/*
Wenbin Wu
CS211 21D
Assignment 19 - continued fractions
*/

#include <iostream>
using namespace std;

double cFraction(int numArr[], int n, int size) {
    if (n == size - 1) return (double) numArr[n];
    
    return (double) numArr[n] + 1 / cFraction(numArr, n+1, size); 
}

int* cFraction(int numArr[], int size) {
    static int v[2] = {1, numArr[size - 1]};
    int temp = v[1];

    for (int i = size - 2; i >= 1; i--) {
        temp = v[1];
        v[1] = numArr[i] * v[1] + v[0];
        v[0] = temp;
    }

    v[0] = numArr[0] * v[1] + v[0];
    return v;
}


int* cFractionRecursive(int numArr[], int n, int size) {
    static int v[2];
    
    if (n == size - 1) {  // base case
        v[0] = 1;
        v[1] = numArr[n];
        return v;
    }

    cFractionRecursive(numArr, n + 1, size);
    
    if (n == 0) {  // when n is 0, don't swap numerator and demoniator
        v[0] = numArr[n] * v[1] + v[0];
        return v;
    }
    
    // when 0 < n < size, swap p/q
    int temp = v[1];
    v[1] = numArr[n] * v[1] + v[0];
    v[0] = temp;
    
    return v; 
}

int main() {
    const int length = 4;
    int x[length] = {7, 2, 4, 2};

    cout << cFraction(x, 0, length) << endl;
    
    int *fraction = cFraction(x, length);
    cout << fraction[0] << " / " << fraction[1] << endl;

    fraction = cFractionRecursive(x, 0, length);
    cout << fraction[0] << " / " << fraction[1] << endl;

    return 0;
}