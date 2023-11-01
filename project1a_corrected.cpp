/*
    Author: Hunter Dowty
    Program: project1a_corrected.cpp
    Date: 10/31/23
    Class: CSC 2400-003 Design of Algorithms
    Purpose: UPDATED Implementation of project 1 part 1, which is the textbook problem 11a on page 8.
*/

#include <iostream>
#include <string>

using namespace std;

void extEuclid(int a, int b); //Extended Euclid's Algorithm
int d, x, y; //global variables

int main()
{
    int a, b;

    cout << "Please give two number values a and b." << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << endl;

    extEuclid(a,b);

    if(d == 0)
    {
        cout << "The GCD of a and b is: UNDEFINED" << endl;
    }
    else
    {
        cout << "The GCD of a and b is: " << d << endl;
    }
        cout << "coefficients x and y are: " << x << " and " << y << endl << endl;

    return 0;
}

//extended Euclid's Algorithm
void extEuclid(int a, int b)
{
    //change a or b to positive if negative:
    if (a < 0)
    {
        a *= -1;
    }
    if (b < 0)
    {
        b *= -1;
    }
    
    //base case
    if(b == 0)
    {
        d = a;
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