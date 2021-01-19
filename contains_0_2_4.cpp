/*
Problem Statement :-
Given a positive integer, starting from 0 to n, count how many numbers
have the digit 0,2,4. Return the count.

Input = 20
Output = 7 (0,2,4,10,12,14,20)

*/

#include <iostream>
#include <string>

using namespace std;

bool contains(int n)
{
    while(n > 0)
    {
        int x = n%10;
        if(x == 0 || x == 2 || x == 4)
        {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main()
{
    int n = 1000000000;
    int count = 1;
    for(int i = 1; i <= n; i++)
    {
        if(contains(i))
        {
            count++;
        }
    }
    cout << count;
    return 0;
}