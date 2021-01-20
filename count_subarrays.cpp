/*
Problem Statement :-
Given an array nums, return the number of subarrays that satisfies the 
following condition. All elements in the subarry must appear atleast
2 times.

Input = [1,2,1,2,4]

Output = 1 (1,2,1,2)

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,3,3,3,3,2,4,4};
    int n = nums.size();
    vector<int> count (n);
    unordered_map<int,int> hash;
    int ans = 0;
    // Traversing the array backwards to store the count of each element
    
    for(int i = n-1; i >= 0; i--)
    {
        hash[nums[i]]++;
        count[i] = hash[nums[i]];
    }

    for(int i = 0; i < n-1; i++)
    {
        if(count[i] == 1)
        {
            continue;
        }
        hash.clear();
        hash[nums[i]]++;
        int temp_count = 0;

        for(int j = i+1; j < n; j++)
        {
            hash[nums[j]]++;
            if(hash[nums[j]] == 2)
            {
                temp_count++;
            }           
            if(temp_count == hash.size()) // Each element in hash occured atleast twice
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}