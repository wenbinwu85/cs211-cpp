#include <iostream>

using namespace std;

bool equivalent(int a[], int b[], int n){
    int shift = 0;
    for (int i = 0; i < n; i++){ 
        if (a[0] == b[i]){
            shift = i;
            break;
        }
    }
    
    for (int i = 0; i < n; i++){
        int b_index = (i + shift) % n;
        if (a[i] != b[b_index]) return false;
    }
    
    return true;
}


int main() {
    int cap = 5;
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {4, 5, 1, 2, 3};
    
    if (equivalent(arr1, arr2, cap)) cout << "They are shift-equivalent." << endl;
    else cout << "They are not shift-equivalent" << endl;
    return 0;    
}