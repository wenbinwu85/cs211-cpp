/*
Wenbin Wu
CS211 21D
Assignment 16 - k bishops in nxn chessboard
*/

#include <iostream>
#include <vector>
using namespace std;
       
bool ok(vector<int> bishops, int n, int position) {
    if (bishops.empty())
        return true;

    int currentRow = position / n;
    int currentCol = position % n; 
    int row, col;
    
    for (int i = 0; i < bishops.size(); i++) {  
        // check if the current position is in any conflict with all previous marked positions
        row = bishops[i] / n;
        col = bishops[i] % n;

        if (abs(currentRow - row) == abs(currentCol - col)) 
            return false;
    }
    return true;
}

void solutions(vector<int> &bishops, int &n, int &k, int &configs) {
    int position = 0;
    
    if (k == 1) {
        configs = n * n;
        return;
    }
    
    while (bishops.size() < k) {
        if (position == n * n) { // backtrack
            if ((bishops.size() == 1) && (bishops.back() == n*n-1)){
                bishops.clear(); 
                return;
            }
            
            position--;
            position = bishops.back() + 1;
            bishops.pop_back();
            continue;
        }

        if (ok(bishops, n, position)) {
            bishops.push_back(position);  // add a valid bishops to the vector
            
            if (bishops.size() == k) {
                configs++;  // increment configuration count
                position = bishops.back();
                bishops.pop_back();
            }
            position++;
        }
        else {
            position++;
        }
    }
    return;
}

int main() {
    int configs = 0, n = 0, k = 0; 

    while (true) {
        vector<int> bishops;  // to store bigshops
        cout << "Enter the size of the chessboard n: ";
        cin >> n;
        if (n < 0) break;
        cout << "Enter the number of bishops k: ";
        cin >> k;

        solutions(bishops, n, k, configs);  // find all configurations
        
        cout << "n\tk\tnumber of configurations" << endl;
        cout << n << "\t" << k << "\t" << configs << endl;
        configs = 0;
    }
    return 0;
}