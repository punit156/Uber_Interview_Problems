/*
Problem Statement :-
Given an array nums, a subarray is a contiguous block of elements.
Given a window size m, find the minimum element of all such subarrays
and return the maximum value among these minimums.
*/

/* Problem is similar to Leetcode 239 (Sliding Window Maximum) */

#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {4,-2,4,4};
    int m = 2;
    int n = nums.size();
    map<int,int> hash;
    int maxi = INT_MIN;
    int i = 0;
    int j = 0;
    for(; j < m; j++)
    {
        hash[nums[j]]++;
    }
    while(j < n)
    {
        auto it = hash.begin();
        if(it->first > maxi)
        {
            maxi = it->first;
        }
        hash[nums[i]]--;
        if(!hash[nums[i]])
        {
            hash.erase(nums[i]);
        }
        hash[nums[j]]++;
        i++;
        j++;
    }
    auto it = hash.begin();
    if(it->first > maxi)
    {
        maxi = it->first;
    }
    cout << maxi;
    return 0;
}