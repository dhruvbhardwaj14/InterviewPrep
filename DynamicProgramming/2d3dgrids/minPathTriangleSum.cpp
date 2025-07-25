#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.*/

/*Approach- 

1. Understand the problem: You're given a triangle where each element can move to the adjacent numbers on the row below. You need to find the minimum path sum from top to bottom.
2. Decide the recursive relation:
   * From any cell `(row, col)`, you can go either to `(row+1, col)` or `(row+1, col+1)`.
   * So, the minimum path sum from `(row, col)` is:
     `triangle[row][col] + min(path from (row+1, col), path from (row+1, col+1))`.
3. Define the function:
   * Name it something like `getMinPath(triangle, row, col, m, dp)`.
   * It returns the minimum path sum starting from cell `(row, col)`.
4. Identify base case:
   * If `row == m - 1` (last row), return `triangle[row][col]` directly because it's the only path left.
5. Add memoization:
   * Use a `dp[row][col]` table to store results of subproblems.
   * If `dp[row][col] != -1`, return it instead of recomputing.
6. Apply recursion:
   * Recursively call the function for `(row+1, col)` and `(row+1, col+1)`.
   * Take the minimum of the two.
   * Add `triangle[row][col]` once (outside the `min`).
7. Store and return the result:
   * Store the result in `dp[row][col]` and return it.
8. In `minimumTotal()` function:
   * Get the size of triangle.
   * Initialize `dp` vector of the same structure as triangle with all values as `-1`.
   * Call the recursive function starting from `(0, 0)`.
9. Return the result of the recursive function as the final answer.
10. Done.
*/
int getMinPath(vector<vector<int>>& triangle,int row,int col,int m,vector<vector<int>>& dp){
    if(row==m-1){
        return triangle[row][col];
    }
    if(dp[row][col]!=-1) return dp[row][col];
    int down = getMinPath(triangle, row + 1, col, m, dp);
    int diag = getMinPath(triangle, row + 1, col + 1, m, dp);

    return dp[row][col] = triangle[row][col] + min(down, diag);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int m=triangle.size();
    vector<vector<int>> dp;
    for(int i=0;i<m;i++) dp.push_back(vector<int>(triangle[i].size(), -1));
    return getMinPath(triangle,0,0,m,dp);
}
int main(){
  
    return 0;
}