// Wu, Wenbin
// CS111 11A Homework 5

#include <iostream>

using namespace std;

int countSeven(int num){
    int count = 0;
    if (num % 10 == 7) count++;
    if (num / 10) count += countSeven(num / 10);
    return count;
}

void printStarDigit(int num){
    if (num < 10) cout << "*" << num << "*";
    else{
        printStarDigit(num/10);
        cout << num % 10 << "*";
    }
    return;
}

int sum(int a[], int num){
    int total = 0;
    for (int i = 0; i < num; ++i) total += a[i];
    return total;
}

bool arraysEqual(int a[], int b[], int num){
    for(int i = 0; i < num; ++i) if (a[i] != b[i]) return false;
    return true;
}

int main() {
    cout << "Part A:\n";
    int input1 = 123456, input2 = 7, input3 = 717171;
    cout << "counting digit 7: " << countSeven(input1) << endl; //should output: 0
    printStarDigit(input1); //should output: *1*2*3*4*5*6*
    cout << endl;
    cout << "counting digit 7: " << countSeven(input2) << endl; //should output: 1
    printStarDigit(input2); //should output: *7*
    cout << endl;
    cout << "counting digit 7: " << countSeven(input3) << endl; //should output: 3
    printStarDigit(input3); //should output: *7*1*7*1*7*1*
    cout << endl;
    
    cout << "\nPart B:\n";
    int a[4] = {3, 4, 5, 2};
    int b[4] = {3, 4, 5, 2};
    int c[5] = {3, 3, 3, 3, 3};
    int d[5] = {3, 3, 3, 3, 4};
    cout << "The elements of array a add up to " << sum(a, 4) << endl;
    if (arraysEqual(a, b, 4))
        cout << "Arrays a and b are equal" << endl;
    else
        cout << "Arrays a and b are not equal" << endl;
    if (arraysEqual(c, d, 5))
        cout << "Arrays c and d are equal" << endl;
    else
        cout << "Arrays c and d are not equal" << endl;
    return 0; 
}