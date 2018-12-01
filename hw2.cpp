// Wu, Wenbin
// CS11 11A Homework 2


#include <iostream>

using namespace std;

int main() {
//Part A
  int amount, hundreds, twenties, tens, fives, singles;
  cout << "How much change in dollars is needed? ";
  cin >> amount;
  
  if (amount < 0){
    cout << "Invalid amount!\n";
    return 0;
  }
  else {
    hundreds = amount / 100;
    amount = amount % 100;
    twenties = amount / 20;
    tens = amount % 20 / 10;
    amount = amount % 10;
    fives = amount / 5;
    singles = amount % 5;
      
    cout << "You need:\n";
    cout << hundreds << " hundred dollar bill(s)\n";
    cout << twenties << " twenty dollar bill(s)\n";
    cout << tens << " ten dollar bill(s)\n";
    cout << fives << " five dollar bill(s)\n";
    cout << singles << " one dollar bill(s)\n";
  }
  cout << endl;


//Part B
  int num, number, first, second, third, fourth, sum;
  cout <<"Please input a 4-digit positive integer: ";
  cin >> num;

  if ((num / 10000 > 0) || (num / 1000 < 1)){
	  cout << "Invalid number!\n";
    return 0;
  }
  else {
    number = num;
    first = number / 1000;
    number = number % 1000;
    second = number / 100;
    number = number % 100;
    third = number / 10;
    fourth = number % 10;
    sum = first + second + third + fourth;

    cout << "The sum of all digits in " << num << " is " << sum << endl;
  }
  cout << endl;

//part c
  int n = 0;
  while (n * n < 11000){
    ++n;
  }
  cout << n << " is the smallest positive integer such that " 
       << n << " squared "<< n * n << " is greater than 11000.\n";
  
  n = 0;
  while (n < 11000){
    if (n * n * n < 11000){
      ++n;
    }
    else{
      --n;
      break;
    }
  }
  
  cout << n << " is the largest positive integer such that " 
       << n << " cubed "<< n * n * n << " is less than 11000.\n";
  cout << endl;
  
  return 0;
}
