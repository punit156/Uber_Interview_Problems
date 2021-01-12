/*
Problem Statement :-
Uber is trying to assess customer route patterns and offer suggestions
to other users based on this. Each from and to for a route can be 
represented as an undirected edge. A group of n locations is uniquely
numbered from 1 to n. A trio is defined as a group of 3 related
locations that are connected with each other. Example [1,2], [2,3], 
[2,3].
Trios are scored by counting the number of nodes outside the trio i.e
how many other nodes are these trio of nodes directly connected to. This
score is known as location sum. 

Given a 'from' and 'to' of all the nodes, determine the minimum location
sum for all trios. If no such trio exists return -1;

Ex :-
Input - 
from = [1,2,2,3,4,4]
to =   [2,4,5,5,5,6]

Output - 3
Nodes 2,4,5 make a trio, and outside the trio they are connected to
three other nodes 1,3,6.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

/* The idea here is to take any two nodes, and find their intersection
nodes. And calculate their degree */

vector<int> intersection (vector<int> v1, vector<int> v2)
{
    vector<int> v3;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    return v3;
}

int main()
{
    vector<int> from = {1,2,2,3,4,5,3};
    vector<int> to = {2,4,5,5,5,6,6};
    int n = from.size();
    map<int, vector<int>> graph;
    map<vector<int>, int> visited_trios;
    for(int i = 0; i < n; i++)
    {
        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }
    int min_sum = -1;
    for(auto it : graph)
    {
        int node = it.first;
        int node_size = it.second.size();
        for(auto neighbor : it.second)
        {
            vector<int> neighbor_neighbors = graph[neighbor];
            int neighbor_size = neighbor_neighbors.size();
            vector<int> shared = intersection(it.second, neighbor_neighbors);
            if(shared.size() > 0)
            {
                for(auto shared_neigh : shared)
                {
                    vector<int> trio;
                    trio.push_back(node);
                    trio.push_back(neighbor);
                    trio.push_back(shared_neigh);
                    sort(trio.begin(), trio.end());
                    if(!visited_trios.count(trio))
                    {
                        visited_trios[trio]++;
                        int degree = node_size + neighbor_size + graph[shared_neigh].size();
                        degree -= 6;

                        /* Here we need to subtract 6 because, each node
                        involved in the trio will count it's other two nodes
                        int the trio as well. And our location sum should 
                        only include nodes outside the trio. Hence -6 
                        (2 for each) */

                        if(min_sum == -1)
                        {
                            min_sum = degree;
                        }
                        else
                        {
                            min_sum = min(min_sum , degree);
                        }
                    }
                }
            }
        }
    }
    cout << min_sum;
    return 0;
}