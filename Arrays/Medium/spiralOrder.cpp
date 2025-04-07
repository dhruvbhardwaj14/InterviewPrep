#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

/*Approach-
In this approach, we will be using four loops to print all four sides of the matrix.
1st loop: This will print the elements from left to right.
2nd loop: This will print the elements from top to bottom.
3rd loop: This will print the elements from right to left.
4th loop: This will print the elements from bottom to top.

steps:-
1. Create and initialize variables top as starting row index, bottom as ending row index left as starting column index, and right as ending column index.
2. In each outer loop traversal print the elements of a square in a clockwise manner.
3. Print the top row, i.e. Print the elements of the top row from column index left to right and increase the count of the top so that it will move to the next row.
4. Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.
5. Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left and decrease the count of bottom
6. Print the left column, i.e. if left <= right, then print the elements of the left column from the bottom row to the top row and increase the count of left.
7. Run a loop until all the squares of loops are printed.

edge cases - 
1. whenever the elements in a single row are traversed they cannot be traversed again backward so the condition is checked in the right-to-left loop.
2. When a single column is present, the condition is checked in the bottom-to-top loop as elements from bottom to top cannot be traversed again.
*/
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int> > matrix(m,vector<int>(n)) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<int> ans;
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;
    while (top<=bottom && left<=right)
    {
        for (int i = left; i <=right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <=bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom){
            for (int i = right; i >=left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for (int i = bottom; i>=top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
    
    return 0;
}