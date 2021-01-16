/*
Problem Statement :-
For two arrays, a lower bound and an upper bound is given. Calculate
how many pairs meet lower <= a[i]**2 + b[i] ** 2 <= upper

Ex:-
Input - a = [2,3], b = [3,4], upper = 18, lower = 10

Output - 2. (2,3 and 3,3)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a = {9,8,7,6,5,4,3,2,1};
    vector<int> b = {1,2,3};
    int upper = 18;
    int lower = 10;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size();
    int m = b.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        a[i] = a[i] * a[i];
    }
    for(int i = 0; i < m; i++)
    {
        b[i] = b[i] * b[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int temp = a[i] + b[j];
            if(temp >= lower && temp <= upper)
            {
                ans++;
            }
            else if (temp > upper)
            {
                break;
            }
        }
    }

    cout << ans;
    return 0;
}