/*
    Author: Hunter Dowty
    Program: project1a_corrected.cpp
    Date: 9/4/23
    Class: CSC 2400-003 Design of Algorithms
    Purpose: UPDATED Implementation of project 1 part 1, which is the textbook problem 11a on page 8.
*/

#include <iostream>
#include <string>

using namespace std;

void extEuclid(int a, int b); //Extended Euclid's Algorithm
int gcd, x, y; //global variables.  gcd is the resultant GCD, while x and y will be the coefficients of GCD.

int main()
{
    int a, b; //a is the first number value, b is the second.  These are to be used in the algorithm.

    cout << "Please give two number values a and b." << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << endl;

    //turn any negative inputs into their positive counterpart:
    if (a < 0)
    {
        a *= -1;
    }
    if (b < 0)
    {
        b *= -1;
    }

    extEuclid(a,b);

    if(gcd == 0)
    {
        cout << "The GCD of a and b is: UNDEFINED" << endl;
    }
    else
    {
        cout << "The GCD of a and b is: " << gcd << endl;
    }
        cout << "coefficients x and y are: " << x << " and " << y << endl << endl;

    return 0;
}

//extended Euclid's Algorithm
void extEuclid(int a, int b)
{   
    //base case
    if(b == 0)
    {
        gcd = a;
        x = 1;
        y = 0;
    }
    else //recursive case
    {
        extEuclid(b, a % b);

        int temp = x;
        x = y;
        y = temp - (a/b) * y;

    }
}