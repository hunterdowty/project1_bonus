/*
    Author: Hunter Dowty
    Program: project1b_corrected.cpp
    Date: 9/4/23
    Class: CSC 2400-003 Design of Algorithms
    Purpose: UPDATED Implementation of project 1 part 2, which asks to implement consecutive
             integer checking algorithm for computing gcd(m,n).
*/

#include <iostream>
#include <string>

using namespace std;

int gcd_consecutive(int a, int b); //Consecutive integer checking Euclid's Algorithm
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

    //turn any negative inputs into their positive values:
    if (a < 0)
    {
        a *= -1;
    }
    if (b < 0)
    {
        b *= -1;
    }

    int result = gcd_consecutive(a,b);

    if(a == 0 && b == 0)
    {
        cout << "The GCD of a and b is: UNDEFINED" << endl;
    }
    else
    {
        cout << "The GCD of a and b is: " << result << endl;
    }

    return 0;
}

int gcd_consecutive(int a, int b)
{
    //initialize the gcd to 1
    gcd = 1;

    //find the minimum of the two numbers
    int min_num = min(a, b);
    
    //if a or b are already 0, the GCD is the other number!
    if (a == 0)
    {
        gcd = b;
    }
    else if (b == 0)
    {
        gcd = a;
    }
    else //check all integer from min_num down to 1
    {
        for (int i = min_num; i > 0; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                gcd = i;
                break; //found the GCD, exit loop!
            }
        }
    } 
    return gcd;
}