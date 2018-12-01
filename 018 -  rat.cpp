/*
Wenbin Wu
CS211 21D
Assignment 18 - rat class
*/


#include <iostream>
using namespace std;

class Rat {
    private:
        int n;
        int d;

        int gcd(int n, int d) {  // find gcd
            if (d == 0) return n;
            return gcd(d, n % d);
        }
        
        Rat reduceRat(Rat r) {  // simpify rat by gcd
            Rat x;
            int common = gcd(r.n, r.d);
            x.n = r.n / common;
            x.d = r.d / common;
            return x;
        }
        
        int checkZero(int num) {  // check if demoninator is 0
            while (num == 0) {
                cout << "Can not divide by 0, enter new demoninator: ";
                cin >> num;
            }
            return num;
        }

    public:
        // constructors
        // default constructor
        Rat() {
            n = 0;
            d = 1;
        }

        // 2 parameter constructor
        Rat(int i, int j) {
            j = checkZero(j);  // check for 0
            int common = gcd(i, j);  // find gcd
            
            n = i / common;  // reduce rat
            d = j / common;
        }

        // conversion constructor
        Rat(int i) {
            n = i;
            d = 1;
        }

        //accessor functions (usually called get() and set(...) )
        int getN() { 
            return n;
        }
        int getD() { 
            return d;
        }
        void setN(int i) {
            n = i;
        }
        void setD(int i) {
            d = checkZero(i);
        }

        //arithmetic operators
        Rat operator+(Rat r) {
            Rat t;
            t.n = n * r.d + d * r.n;
            t.d = d * r.d;
            return reduceRat(t);
        }

        Rat operator-(Rat r) {
            Rat t;
            t.n = n * r.d - d * r.n;
            t.d = d * r.d;
            return reduceRat(t);
        }
        
        Rat operator*(Rat r) {
            Rat t;
            t.n = n * r.n;
            t.d = d * r.d;
            return reduceRat(t);
        }
        
        Rat operator/(Rat r) {
            Rat t;
            t.n = n * r.d;
            t.d = d * r.n;
            return reduceRat(t);
        }
        // 2 overloaded i/o operator
        friend ostream& operator<<(ostream& os, Rat r);
        friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r) {
    int common = r.gcd(r.n, r.d);
    r.n = r.n / common;
    r.d = r.d / common;
    
    int i = r.n / r.d;
    int j = r.n % r.d;

    if (i > 0)
        os << i << " ";
    
    if (j == 0) {
        os << endl;
        return os;
    }
    
    else if (j > 0)
        os << j << "/" << r.d << endl;
        
    else
        os << r.n << "/" << r.d << endl;
    return os;
 }
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r) {
    int  d;
    is >> r.n >> d;
    r.setD(d);  // use setter method to void direct assignment of 0 to r.d

    return is;
}

int main(){
    Rat x(1,2), y(2,3), z;
    z = x + y;
    cout << z;
    x.setN(3);
    y.setD(2);
    z = x + y;
    cout << z;
    cin >> x;
    cout << x;
    z = x + 5;
    cout << z;
    return 0;
}