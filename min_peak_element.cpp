/*
Problem Statement :-
Find the minimum peak element from the array, remove it, and find 
next minimum peak until the array is empty. Return a list of min peaks.

A peak element is an element whose neighbors are strictly smaller that
element itself. For edge elements (0 and n-1), consider only single 
neighbor. If multiple peak elements in the array, select the min peak 
for removal.

Eg :-
Input = [1,5,3,7,2]

Output = [5,7,3,2,1]

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {1,9,7,8,2,6};
    int n = nums.size();
    int i = 0;
    vector<int> ans;
    while(i < n)
    {
        if(nums.size() == 1)
        {
            ans.push_back(nums[0]);
            break;
        }
        int mini = INT_MAX;
        int index = -1;
        int size = nums.size();
        for(int j = 0; j < size; j++)
        {
            int left;
            int right;
            if(j == 0)
            {
                left = INT_MIN;
            }
            else
            {
                left = nums[j-1];
            }
            if(j == size-1)
            {
                right = INT_MIN;
            }
            else
            {
                right = nums[j+1];
            }
            if(nums[j] > left && nums[j] > right && nums[j] < mini)
            {
                mini = nums[j];
                index = j;
            }
        }
        ans.push_back(nums[index]);
        nums.erase(nums.begin() + index);
        i++;
    }

    i = 0;
    while(i < n)
    {
        cout << ans[i] << " ";
        i++;
    }
    
    return 0;
}