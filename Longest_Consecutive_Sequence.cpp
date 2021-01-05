/*
Problem Statement :-
Given an unsorted array of integers nums, return the length of the 
longest consecutive subsequence.
(Leetcode 128)
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    int n = nums.size();
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    map <int,int> hash;
    for(int i = 0; i < n; i++)
    {
        hash[nums[i]];
    }
    auto prev = hash.begin();
    int count = 1;
    int max = 0;
    for(auto it = hash.begin(); it != hash.end(); it++)
    {
        if(prev->first + 1 == it->first)
        {
            count++;
        }
        else
        {
            if(count > max)
            {
                max = count;
            }
            count = 1;
        }
        prev = it;
    }
    if(count > max)
    {
        cout << count;
        return 0;
    }
    cout<<max;
    return 0;
}