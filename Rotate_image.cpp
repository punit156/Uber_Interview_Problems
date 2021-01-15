/*
Problem Statement :-
Given a matrix, rotate it 90 degree clockwise, such that, the elements
on both major diagonals remain intact.

Do it in place, don't use second matrix.

For Ex :-
Input =  [[1,2,3]
          [4,5,6]
          [7,8,9]]

Output = [[1,4,3]
          [8,5,2]
          [7,6,9]]

*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    vector<vector<int>> matrix = {{1,2}, {3,4}};
    int n = matrix.size();
    cout << "Before" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "After" << endl;
    // K indicates the row. We only need to go till (n/2) - 1 rows
    for(int k = 0; k < n/2; k++)
    {
        // i indicates the columns.
        for(int i = k+1; i < n-1-k; i++)
        {
            int row = k;
            int col = i;
            int temp = matrix[row][col];
            
            matrix[row][col] = matrix[n-1-col][row];
            // j is fixed. We repeat the swap 3 times. One for each directoion
            for(int j = 0; j < 3; j++)
            {
            int temp_row = row;
            row = col;
            col = n-1-temp_row;
            swap(temp, matrix[row][col]); 
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}