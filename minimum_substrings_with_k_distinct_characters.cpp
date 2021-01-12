/*
Problem Statement :-
Given a string str and an integer k, your task is to split str into a 
minimal possible number of substrings so that there are no more than
k different symbols in each of them. Return the minimal possible
number of such substrings.

Ex :-
Input -
str = "aabeefegeeccrr", k = 3

Output = 3
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string str = "aabeefegeeccrr";
    int k = 1;
    unordered_map<char, int> hash;
    int ans = 0;
    for(auto c : str)
    {
        hash[c]++;
        if(hash.size() > k) // More than k unique characters
        {
            hash.clear();
            ans++;
            hash[c]++;
        }
    }
    cout << ans + 1;
    return 0;
}