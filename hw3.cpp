//Wu, Wenbin
//CS111 11A Homework 3

#include <iostream>

using namespace std;
int main(){
	//part A
	int num1, num2, diff;
	string prompt1 = "Enter a 2 digit number: ";
	
	while (true){
		cout << prompt1;
		cin >> num1;
		if (num1 == 0){
			cout << "Program terminated.";
			return 0; 
		}
		cout << "Enter another 2 digit number: ";
		cin >> num2;
		
		if ((10 > num1 || num1 > 99) || (10 > num2 || num2 > 99)){
			prompt1 = "Input is illegal. Try again or press 0 to exit: ";
		}
		else{ 
	    	diff = num1 - num2;
			if (diff < 0) cout << -1 * diff; else cout << diff;
			cout <<endl;
			break;
		}
	}
	
	//part B
	int size;
	do{
		cout << "Enter a odd number between 10 and 20: ";
		cin >> size;
	}while ((size < 10 || size > 20) || size % 2 == 0);
	
	int middle = size/2+1, half = size/2;
	for (int r = 1; r <= size; r++){
		for (int copies = 1; copies <= 3; copies++){
			for (int c = 1; c <= size; c++){
				if (c == r || c == size-r+1) cout << "*";
				else if (c == middle) cout << "&";
				else if (r == middle && c <=half) cout << "x";
				else if (r == middle && c >=half) cout << "+";
				else cout << " ";
			}
			cout << "   ";
		}
		cout << endl;
	}
		
 	return 0;
}