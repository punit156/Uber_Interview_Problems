/*
Problem Statement :-
Return top K frequent elements from an array.


Ex :-
Input - nums = [4,4,200,1,1,2], K = 2
Output - [1,4]

*/

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {1,1,1,200,4,4,2,2,2};
    int n = nums.size();
    int k = 2;
    unordered_map<int,int> hash;
    for(auto n : nums)
    {
        hash[n]++;
    }
    priority_queue <pair<int,int>> pq;
    for(auto it = hash.begin(); it != hash.end(); it++)
    {
        pq.push({it->second, it->first});
    }
    while(k > 0)
    {
        auto temp = pq.top();
        pq.pop();
        cout << temp.second << " ";
        k--;
    }
    return 0;
}