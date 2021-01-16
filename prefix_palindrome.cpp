/*
Problem Statement :-
Given a string, find a prefix such that it is palindrome and 
it's length is > 2. Remove that prefix and repeat the process, until
no such prefix left. Select the longest palindrome each time.

Ex :-
Input = "aaaabcbd"

Output = "d"

*/

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    string s = "aaad";
    int i = s.size();
    for(; i >= 0; i--)
    {
        string temp = s.substr(0,i);
        if(temp.size() > 2 && is_palindrome(temp))
        {
            s = s.substr(i);
            i = s.size();
        }
        if(s.size() <= 2)
        {
            break;
        }
    }

    cout << s;
    return 0;
}