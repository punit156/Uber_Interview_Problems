/*
Problem Statement :-
Given input array with asteroid size and direction, find out the result
after the collision.
Negative means moving right, positive means moving left.

Ex:-
Input = [-6,4,10]
Output = [10]
-6 collides with 4 and 4 gets destroyed.
Then -6 collides with 10 and -1 gets destroyed.

Modification of Leetcode 735

*/

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main()
{
    vector<int> asteroids = {-2,-1,1,2};
    stack <int> st;
    for(auto ast : asteroids)
    {
        if(st.empty())
        {
            st.push(ast);
            continue;
        }
        if(ast > 0) // Moving left
        {
            bool flag = true;
            while(!st.empty())
            {
                if(st.top() > 0)
                {
                    break;
                }
                else if(st.top() < 0 && abs(st.top()) > ast)
                {
                    flag = false;
                    break;
                }
                else if(st.top() < 0 && abs(st.top()) < ast)
                {
                    st.pop();
                }
                else // Both same in magnitude, they destroy eachother
                {
                    st.pop();
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                st.push(ast);
            }
        }
        else // Negative, moving right
        {
            st.push(ast);
        }
    }

    int n = st.size();
    vector<int> ans (n);
    for(int i = n-1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}