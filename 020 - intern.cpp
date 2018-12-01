/*
Wenbin Wu
CS211 21D
Assignment 20 - intern
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, int> codes;
    vector<string> tornPapers = {"011", "0111", "01110", "111", "0111", "10111"};

    for (auto i : tornPapers) {  // concatenate 2 pieces of code together and add it to a map
        for (auto j : tornPapers) {
            if (codes.count(i+j) == 0) codes[i+j] = 1;  // if the code is not alreay in the map, count = 1
            else codes[i+j]++;  // if the coe is already in the map, count++
        }
    }
    
    int numOfPaper = tornPapers.size() / 2;
    for (auto c : codes) {
        if (c.second >= numOfPaper)  // the code with the most count is the real code
            cout << "The real code is: "<< c.first << endl;
    }
    
    return 0;
}