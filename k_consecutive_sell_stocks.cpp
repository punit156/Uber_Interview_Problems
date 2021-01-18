/*
Problem Statement :-
You are given prices, an array where prices[i] represents the price of
stock on ith day. An array algo, of 1's and 0's, that gives bot's
schedule, 0 means buy and 1 means sell. And an integer k.

To improve bot's performance, you have to change the bot's schedule to 
include k consecutive 1's such that it can get max revenue.

Eg :-
Input - 
prices = {2,4,1,5,2,6,7}, algo = {0,1,0,0,1,0,0}, k = 4

Output = 21
We change algo to {0,1,0,1,1,1,1}.

Hint :- We are going to use sliding window technique.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> prices = {2,4,1,5,2,6,7,8,3,6,1,9};
    vector<int> algo =   {0,1,0,0,1,0,0,1,0,1,1,0};
    int k = 3;
    int n = prices.size();

    // First we calculate the profit without changing current schedule.
    
    int runSum = 0;
    for(int i = 0; i < n; i++)
    {
        if(algo[i] == 0) // Buy
        {
            runSum -= prices[i];
        }
        else // Sell
        {
            runSum += prices[i];
        }
    }

    int ans = runSum;

    /* Now we use sliding window and change first k days as 1 (sell),
    then shift our window by 1 in each iteration. */

    int i = 0;
    while(i < k) // First k days
    {
        if(algo[i] == 0) // Currently 0, make it to 1
        {
            runSum += 2*prices[i];

            // We multiplied by 2, because in our original runSum 
            // we had subtracted prices[i] and now we're adding it 
            // hence we need to add twice the amount.
        }

        // If algo[i] is already 1, we don't need to do anything.

        i++;
        ans = max(ans, runSum);
    }
    
    while(i < n)
    {
        //Shifting the window by one unit to the right, so adding 
        // new entries.

        if(algo[i] == 0)
        {
            runSum += 2*prices[i];
        }

        //Deleting old entries by one as we shift to the right.

        if(algo[i-k] == 0)
        {
            runSum -= 2*prices[i-k];
        }
        i++;
        ans = max(ans, runSum);
    }

    cout << ans;
    return 0;
}