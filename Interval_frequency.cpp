/* 
Problem Statement :-
Given a list [s1,e1], [s2,e2], [s3,e3]...Return the frequency of 
intervals.

Eg :-
Input - [[0,3], [1,4], [2,7]]

Output - 
[0,1]->1
[1,2]->2
[2,3]->3
[3,4]->2
[4,7]->1

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<vector<int>> intervals = {{5,7}, {3,5}, {0,3}};
    map<int, int> hash;
    for(auto i : intervals)
    {
        hash[i[0]]++;
        hash[i[1]]--;
    }
    map<pair<int,int>, int> ans;
    auto it = hash.begin();
    int freq = it->second;
    int start_time = it->first;
    it++;
    for(; it != hash.end(); it++)
    {
        if(freq == 0)
        {
            start_time = it->first;
            freq = it->second;
            continue;
        }
        int end_time = it->first;
        ans[{start_time, end_time}] = freq;
        freq += it->second;
        start_time = end_time;
    }

    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << "[" << it->first.first << "," << it->first.second << "]->" << it->second << endl;
    }
    return 0;
}