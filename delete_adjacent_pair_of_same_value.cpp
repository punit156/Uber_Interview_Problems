/*
Problem Statement :-
Given an array A, delete the adjacent pair of the same value, i.e at each
step remove the pair (A[i] == A[i+1]). Game starts with player 1, one
step at a time. If there are no numbers to delete, game is over. The 
one who takes the last step wins. Return who won.

Input = [1,0,1,0,0,1,0]

Output = Player 1

*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    vector<int> A = {1,0,1,1};
    stack <int> st;
    string winner = "";
    for(auto a : A)
    {
        if(!st.empty() && st.top() == a)
        {
            st.pop();
            if(winner == "Player 1")
            {
                winner = "Player 2";
            }
            else
            {
                winner = "Player 1";
            }
        }
        else
        {
            st.push(a);
        }
    }
    cout << winner;
    return 0;
}