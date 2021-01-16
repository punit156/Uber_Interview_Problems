/*
Problem Statement :-
Given a number, output the difference between the product of digits and
sum of digits of the given number.

Eg :-
Input - n = 123

Output = 0

*/

#include <iostream>

using namespace std;

int main()
{
    int n = 1234;
    int product = 1;
    int sum = 0;
    while(n > 0)
    {
        int x = n%10;
        product *= x;
        sum += x;
        n /= 10;
    }

    cout << product - sum;
    return 0;
}