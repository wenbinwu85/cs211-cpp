// Wu, Wenbin
// CS111 11A Homework 6

#include <iostream>

using namespace std;

int smallCol(int arr[2][3], int row, int col){
    int smallest = 0, sum = 0;
    for (int i = 0; i < row; i++) smallest += arr[i][0];
    for (int j = 1; j < col; j++){
        for (int k = 0; k < row; k++) sum += arr[k][j];
        if (sum < smallest) smallest = sum;
        sum = 0;
    }
    return smallest;
}


string toUpperCase(string str){
    for (int i = 0; i < str.size(); i++){
        if (str[i] >= 97 && str[i] <= 122) str[i] = (char) str[i] - 32;
    }
    return str;
}


void toLowerCase(string& str){
    for (int i = 0; i < str.size(); i++){
        if (str[i] >=65 && str[i] <= 90) str[i] = (char) str[i] + 32;
    }
}


bool equals(string s1, string s2){
    if (s1 == s2) return true;
    else return false;
}


int main(){
    int x[2][3] = {{3, 1, 4}, {1, 5, 9}};
    cout << "Smallest column sum = " << smallCol(x, 2, 3) << endl;
    // from the 2-d array x that has size 2 x 3, find the smallest col sum/Users/ahben/Desktop/dil.cpp
    // output will be 4 since col#0 contains 3 and 1 is smallest.
    cout << endl;

    string str1, str2, str1Upper, str2Upper;
    cout << "Please enter 2 words: ";
    cin >> str1 >> str2;
    str1Upper = toUpperCase(str1);
    str2Upper = toUpperCase(str2);
    cout << "Words in uppercase: " << str1Upper << " " << str2Upper << endl;
    toLowerCase(str1Upper);
    toLowerCase(str2Upper);
    cout << "Words in lowercase: " << str1Upper << " " << str2Upper << endl;
    if (equals(str1, str2)) cout << "both strings are equal.\n";
    else cout << "The input strings are different.\n";
    return 0;
}