#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.*/
/*Approach-
1. Define a function `uniquePathsWithObstacles` that takes the grid `obstacleGrid`.
2. Get the dimensions `m` (rows) and `n` (columns) of the grid.
3. Initialize a `dp` table of size `m x n`, filled with 0s.
4. If the starting cell `(0, 0)` has an obstacle, return 0 (no paths possible).
5. Set `dp[0][0] = 1` since the starting point is valid and reachable.
6. Fill the **first column**:
   * For each cell `(i, 0)`, if there's no obstacle, set `dp[i][0] = dp[i-1][0]`.
7. Fill the **first row**:
   * For each cell `(0, j)`, if there's no obstacle, set `dp[0][j] = dp[0][j-1]`.
8. Fill the rest of the grid using nested loops from `i = 1 to m-1` and `j = 1 to n-1`:
   * If current cell `(i, j)` is not an obstacle, set `dp[i][j] = dp[i-1][j] + dp[i][j-1]`.
9. Return `dp[m-1][n-1]` as the number of unique paths to the bottom-right corner.
 */
// recursive
int getWays(vector<vector<int>>& obstacleGrid,int m,int n,int row,int col){
    if(row==m-1&&col==n-1&&obstacleGrid[m-1][n-1]==0) return 1;
    if(row>=m || col>=n ||obstacleGrid[row][col]==1) return 0;
    return getWays(obstacleGrid,m,n,row+1,col)+getWays(obstacleGrid,m,n,row,col+1);
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    return getWays(obstacleGrid,m,n,0,0);
}
// memoization
int getWays(vector<vector<int>>& obstacleGrid,int m,int n,int row,int col,vector<vector<int>>& dp){
    if(row==m-1&&col==n-1&&obstacleGrid[m-1][n-1]==0) return 1;
    if(row>=m || col>=n ||obstacleGrid[row][col]==1) return 0;
    if(dp[row][col]!=-1)return dp[row][col];
    return dp[row][col]=getWays(obstacleGrid,m,n,row+1,col,dp)+getWays(obstacleGrid,m,n,row,col+1,dp);
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return getWays(obstacleGrid,m,n,0,0,dp);
}
// tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // Create a dp table of same size initialized to 0
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // If starting cell has obstacle, return 0 paths
    if(obstacleGrid[0][0] == 1) return 0;

    // Starting point is reachable
    dp[0][0] = 1;

    // Fill the first column
    for(int i = 1; i < m; i++) {
        if(obstacleGrid[i][0] == 0)
            dp[i][0] = dp[i-1][0];
    }

    // Fill the first row
    for(int j = 1; j < n; j++) {
        if(obstacleGrid[0][j] == 0)
            dp[0][j] = dp[0][j-1];
    }

    // Fill rest of the dp table
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main(){
  
    return 0;
}