/*
    Author: Hunter Dowty
    Program: project1c_corrected.cpp
    Date: 9/4/23
    Class: CSC 2400-003 Design of Algorithms
    Purpose: UPDATED Implementation of project 1 part 3, which asks to implement the middle school
             procedure for computing gcd(m,n).
*/

#include <iostream>
#include <string>
#define MAXFACTORS 1024

using namespace std;
 
// struct to store factorization of m and n
typedef struct
{
 
    int size;
    int factor[MAXFACTORS + 1];
    int exponent[MAXFACTORS + 1];
 
} FACTORIZATION;
 
// Function to find the factorization of M and N
void FindFactorization(int x, FACTORIZATION* factorization)
{
    int i, j = 1;
    int n = x, c = 0;
    int k = 1;
    factorization->factor[0] = 1;
    factorization->exponent[0] = 1;
 
    for (i = 2; i <= n; i++) {
        c = 0;
 
        while (n % i == 0) {
            c++;
 
            // factorization->factor[j]=i;
            n = n / i;
            // j++;
        }
 
        if (c > 0) {
            factorization->exponent[k] = c;
            factorization->factor[k] = i;
            k++;
        }
    }
 
    factorization->size = k - 1;
}
 
// Function to print the factors
void DisplayFactorization(int x, FACTORIZATION factorization)
{
 
    int i;
    cout << "Prime factor of << x << = ";
 
    for (i = 0; i <= factorization.size; i++) {
 
        cout << factorization.factor[i];
 
        if (factorization.exponent[i] > 1)
            cout << "^" << factorization.exponent[i];
 
        if (i < factorization.size)
            cout << "*";
 
        else
            cout << "\n";
    }
}
 
// function to find the gcd using Middle School procedure
int gcdMiddleSchoolProcedure(int m, int n)
{
 
    FACTORIZATION mFactorization, nFactorization;
 
    int r, mi, ni, i, k, x = 1, j;
 
    // Step 1.
    FindFactorization(m, &mFactorization);
    DisplayFactorization(m, mFactorization);
 
    // Step 2.
    FindFactorization(n, &nFactorization);
    DisplayFactorization(n, nFactorization);
 
    // Steps 3 and 4.
    // Procedure algorithm for computing the
    // greatest common divisor.
    int min;
    i = 1;
    j = 1;
    while (i <= mFactorization.size && j <= nFactorization.size) {
        if (mFactorization.factor[i] < nFactorization.factor[j])
            i++;
 
        else if (nFactorization.factor[j] < mFactorization.factor[i])
            j++;
 
        else /* if arr1[i] == arr2[j] */
        {
            min = mFactorization.exponent[i] > nFactorization.exponent[j]
                      ? nFactorization.exponent[j]
                      : mFactorization.exponent[i];
 
            x = x * mFactorization.factor[i] * min;
            i++;
            j++;
        }
    }
 
    return x;
}
 
int main() 
{
 
    int m = 10, n = 15;
    cout << "GCD(" << m << ", " << n << ") = "
         << gcdMiddleSchoolProcedure(m, n);
 
    return (0);
}