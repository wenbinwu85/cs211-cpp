//Wu, Wenbin
//CS111 11A Homework 4

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool largerThan11(int num){
    return num > 11;
}


int rollDice(){
    return rand() % 6 + 1;
}


void emphasis(string s){
    for(int i = 1; i <= 3; i++) cout << s;
    return;
}


void computeRectangle (double& len, double& wid, double& area, double& perimeter){
    perimeter = (len + wid)*2;
    area = len * wid;
    return;
}


void swap(double& area, double& perimeter){
    double temp = area;
    area = perimeter;
    perimeter = temp;
    return;
}


int main(){
    srand(time(0));
    
    cout << "Part A:\n";
    while (true){
        int roll1 = rollDice(), roll2 = rollDice(), roll3 = rollDice();
        int sum = roll1 + roll2 + roll3;
        string shout = "Yes! Finally.";
        
        cout << "Roll dice: " << roll1 << " " << roll2 << " " << roll3;
        cout << " sum = " << sum << endl;
        
        if (largerThan11(sum)){
            emphasis(shout);
            break;
        }
    }
    
    cout << "\nPart B:\n";
    double len = 2.5, wid = 5, area = 0, perimeter = 0;
    computeRectangle(len, wid, area, perimeter);
    cout << "Area of Rectangle = " << area << " and its Perimeter = " << perimeter << endl;
    swap(area, perimeter);
    cout << "Values in area and perimeter are swapped: " << area << " " << perimeter << endl;
    return 0;
}