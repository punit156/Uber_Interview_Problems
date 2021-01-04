/*
Problem Statement :-
Given two integer arrays A and B, and an integer value d, find the 
comparator value between these two arrays.
The comparator is defined as the number of elements x in A such that
there are no elements y in B where |x-y| <= d. In other words, it's the
number of elements in A that are more than 'd' away from any elements
of B.

Eg :-
A = [2,9]
B = [16,13,8]
d = 3

For n = 9, 9-8 = 1 < 3

For n = 2, all |x - y| are <= d.

Therefore ans = 1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A = {2,9};
    vector<int> B = {16,13,8};
    int d = 3;
    int count = 0;
    sort(B.begin(), B.end());
    /* The logic is, for every element a of A, find the range 'd' units
    away from a. For eg :- In case of 2, the range is [-1,5]. If there 
    is any element within this bracket in B, then a cannot be 
    considered as a comparator.
    */
    for(auto a : A)
    {
        auto i = lower_bound(B.begin(), B.end(), a - d);
        auto j = upper_bound(B.begin(), B.end(), a + d);
        count += (i == j);
    }
    cout << count; 
    return 0;
}