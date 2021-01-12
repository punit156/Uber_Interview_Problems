/*
Problem Statement :-
AI of a game picks an integer from the list 1..N with a probability P(i)
for all 1 <= i <= N. You have K attempts to guess the number. On each
guess AI will tell you whether the number is higher or lower than 
our guess. If we can guess within K attempts we win. Find out the 
probability of winning.

Input :-
probability - [0.2, 0.3, 0.4, 0.1, 0], K = 1

Output :-
0.4
*/

/*
The idea here is that given K attempts, you pick (2*k - 1) of the 
highest attempts.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> p = {0.2, 0.3, 0.4, 0.1, 0};
    int n = p.size();
    int k = 1;
    int total = min(n, 2*k - 1);
    sort(p.begin(), p.end());
    double ans = 0.0;
    int i = n-1;
    while(total > 0)
    {
        ans += p[i];
        i--;
        total--;
    }
    cout << ans;
    return 0;
}