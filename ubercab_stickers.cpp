/*
Problem Statement :-
Uber has "ubercab" stickers. Given a word, determine, how many stickers
are needed to make the word.

Ex :-
Input - "abc"
Output = 1

*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    string word = "ubb ercaz";
    unordered_map<char,int> hash;
    hash['u'] = 0;
    hash['b'] = 0;
    hash['e'] = 0;
    hash['r'] = 0;
    hash['c'] = 0;
    hash['a'] = 0;
    int ans = 0;
    for(auto c : word)
    {
        if(c == ' ') // Spaces are allowed
        {
            continue;
        }
        if(!hash.count(c)) //Anything other than "ubercab"
        {
            cout << -1;
            return 0;
        }
        if(c == 'b')
        {
            hash['b']++;
            int needed = hash['b'] / 2;
            if(hash['b'] % 2) // Odd
            {
                needed++;
            }
            ans = max(ans, needed);
        }
        else
        {
            hash[c]++;
            ans = max(ans, hash[c]);
        }
    }
    cout << ans;
    return 0;
}