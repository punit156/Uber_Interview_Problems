/*
Problem Statement :-
Implement a modified hashmap which supports following functions :-
1) Insert(x,y) - insert an object with key x and value y
2) get (x) - return the value of an object with key x
3) addtoKey (x) - add x to all keys in map
4) addtoValue (y) - add y to all values in map

Input will be two arrays :-
queryTypes = ["insert", "insert", "get", "addtoKey"]
queries = [[3,4], [4,5], [3], [2]]

Your function should implement all these queries and in the end return
the sum of all the results for 'get' operations.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> queryTypes = {"insert", "insert", "addtoKey", "get"};
    vector<vector<int>> query = {{3,4}, {4,5}, {3}, {4}};
    int n = query.size();

    /* For all the addtoKey and addtoValue, instead of updating all 
    objects we will just update one cummulative variable. */

    int ck = 0; //Cummulative key
    int cv = 0; //Cummulative value
    unordered_map <int,int> hash;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(queryTypes[i] == "insert")
        {
            int key = query[i][0];
            int value = query[i][1];
            hash[key - ck] = value - cv;
        }
        else if(queryTypes[i] == "get")
        {
            int key = query[i][0];
            ans += hash[key - ck];
        }
        else if(queryTypes[i] == "addtoKey")
        {
            ck += query[i][0];
        }
        else  //Add to value
        {
            cv += query[i][0];
        }
    }
    cout << ans;
    return 0;
}