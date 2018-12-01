// Wu, Wenbin
// CS111 11A Homework 1

#include <iostream>

using namespace std;

int main (){
    //Part A
    char first_char = '$', second_char;

    cout << "Please enter a single character: \n";
    cin >> second_char;
    cout << "The first charcter is: " << first_char;
    cout << " and the second character is: " << second_char << endl;
    cout << endl;

    //Part B
    double feet, inches;
    double height;
    double foot_in_cm = 30.48;

    cout << "How tall are you (feet)?\n";
    cin >> feet;
    cout << "How tall are you (inches)?\n";
    cin >> inches;
    height = (feet + inches/12)*foot_in_cm;
    cout << "Your height is " << height << " in cm.\n";
    cout << endl;

    //Part C
    double base1, base2, trapezoid_height;
    double area;

    cout << "What is the height of the trapezoid?\n";
    cin >> trapezoid_height;
    cout << "What is the base 1 of the trapezoid?\n";
    cin >> base1;
    cout <<"What is the base 2 of the trapezoid?\n";
    cin >> base2;
    area = 0.5 * trapezoid_height * (base1 + base2);
    cout<< "The area of the trapezoid is: " << area <<endl;
    cout << endl;

    return 0;
}
