/*
Problem Statement :-
Given a list of airline tickets represented by pairs of [from, to],
reconstruct itinerary in order. Starting airport is always "JFK".

Constraints :-
-> If multiple valid answers, return the lexicographically smaller one.
-> All tickets must be used once and only once.

Input - [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output - ["JFK", "MUC", "LHR", "SFO", "SJC"]

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;


vector<string> ans;
unordered_map <string, priority_queue<string, vector<string>, greater<string>>> freq;

/* I used priority queue as min heap because I need the lexicographically
smallest string if there are multiple entries for an airport. */

/* The idea behind DFS is to find the last airport i.e the airport which
has no entry in hash. We are constructing out itinerary in reverse order.
This way we ensure that all airports are visited atleast once. */

void dfs(string temp)
{
    while(freq[temp].size() > 0)
    {
        string temp2 = freq[temp].top();
        freq[temp].pop();
        dfs(temp2);
    }
    ans.push_back(temp);
}
int main()
{
    vector<vector<string>> tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};

    // Populate the hash

    for(auto t : tickets)
    {
        freq[t[0]].push(t[1]);
    }

    dfs("JFK");
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}