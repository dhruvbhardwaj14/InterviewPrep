#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.*/
/*Approach- 
Sure. Here's the step-by-step linewise approach to write the recursive + memoization solution for the **Minimum Path Sum** problem, along with explanation of `dp[i][j]`.

---

Problem: Given an `m x n` grid filled with non-negative numbers, find a path from the top-left to the bottom-right, which minimizes the sum of all numbers along its path. You can only move **right or down**.

---

Step-by-step recursive + memoization approach:

1. Define a function `getMinPath(grid, i, j, m, n, dp)` to compute the minimum path sum from cell `(i, j)` to `(m-1, n-1)`.

2. Base case:
   If `i == m-1` and `j == n-1`, return `grid[i][j]` because you're already at the destination.

3. Boundary case:
   If `i >= m` or `j >= n`, return a very large number (like `INT_MAX`) since it's an invalid path and should not be chosen in `min()`.

4. Memoization:
   If `dp[i][j]` is not `-1`, return `dp[i][j]` because you've already computed the answer for this cell.

5. Recursive calls:
   Calculate the cost of moving down: `getMinPath(grid, i+1, j, m, n, dp)`
   Calculate the cost of moving right: `getMinPath(grid, i, j+1, m, n, dp)`

6. Store the minimum cost path from `(i, j)` in `dp[i][j]`:
   `dp[i][j] = grid[i][j] + min(down, right)`

7. Return `dp[i][j]`

8. In the main function `minPathSum(grid)`,

   * Get `m = grid.size()` and `n = grid[0].size()`
   * Create `dp` of size `m x n` initialized with `-1`
   * Return `getMinPath(grid, 0, 0, m, n, dp)`


Definition of dp\[i]\[j]:
`dp[i][j]` represents the minimum path sum to reach the bottom-right cell `(m-1, n-1)` starting from the current cell `(i, j)`. It stores the result of the subproblem to avoid recomputation and optimize the recursive solution.
*/

// recursive
int getMinPath(vector<vector<int>>& grid,int row,int col,int m,int n){
    if(row==m-1 && col==n-1){
        return grid[row][col];
    }
    if(row>=m || col>=n) return INT_MAX;
    int left=grid[row][col]+min(getMinPath(grid,row+1,col,m,n),getMinPath(grid,row,col+1,m,n));
    return left;
}
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    return getMinPath(grid,0,0,m,n);
}

// memoization
int getMinPath(vector<vector<int>>& grid,int row,int col,int m,int n,vector<vector<int>>& dp){
    if(row==m-1 && col==n-1){
        return grid[row][col];
    }
    if(row>=m || col>=n) return INT_MAX;
    if(dp[row][col]!=-1) return dp[row][col];
    return dp[row][col]=grid[row][col]+min(getMinPath(grid,row+1,col,m,n,dp),getMinPath(grid,row,col+1,m,n,dp));;
}
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return getMinPath(grid,0,0,m,n,dp);
}

// tabulation
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    // return getMinPath(grid,0,0,m,n,dp);
    dp[m-1][n-1]=grid[m-1][n-1];
    // Fill last row (can only come from left)
    for(int j = n-2; j >= 0; j--) {
        dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
    }

    // Fill last column (can only come from below)
    for(int i = m-2; i >= 0; i--) {
        dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}
int main(){
  
    return 0;
}