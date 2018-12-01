#include <iostream>

using namespace std;
int main() {
    int num = 1;
    
    while (num < 100){
        int square = num * num;
        int last2 = square % 100;
        int second = last2 / 10;
        int first = last2 % 10;
        
        if ((second % 2) != 0 and (first % 2) != 0){
            cout << square;
            break;
        }
        ++num;
    }
    cout << "No solution!";
    return 0;
}