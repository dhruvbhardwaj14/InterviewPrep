#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.*/
/*Approach-
1. Define a function `uniquePaths(m, n)` that takes two integers: number of rows `m` and number of columns `n`.
2. Create a 2D vector `dp` of size `m x n` and initialize all values to 0. This table will store the number of unique paths to reach the bottom-right from each cell.
3. Fill the last row of the grid (row index `m-1`) with 1s. This is because from any cell in the last row, there's only one way to reach the end — move right.
4. Fill the last column of the grid (column index `n-1`) with 1s. This is because from any cell in the last column, there's only one way to reach the end — move down.
5. Loop `i` from `m-2` down to `0` (from second-last row up to first row):
   * Inside this loop, loop `j` from `n-2` down to `0` (from second-last column to first column):
     * For each `dp[i][j]`, set it equal to the sum of the cell directly below it (`dp[i+1][j]`) and the cell directly to its right (`dp[i][j+1]`).
6. After filling the table, return `dp[0][0]`, which contains the number of unique paths from the top-left corner to the bottom-right corner.
*/
// recursive
int findWay(int row,int col,int m,int n){
    if(row==m-1 && col==n-1) return 1;
    if(row>=m || col>=n) return 0;
    return findWay(row+1,col,m,n)+findWay(row,col+1,m,n);
}
int uniquePaths(int m, int n) {
    return findWay(0,0,m,n);
}

// memoization
int findWay(int row,int col,int m,int n, vector<vector<int>>& dp){
    if(row==m-1 && col==n-1) return 1;
    if(row>m-1|| col>n-1) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    return dp[row][col]=findWay(row+1,col,m,n,dp)+findWay(row,col+1,m,n,dp);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return findWay(0,0,m,n,dp);
}
// tabulation
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    dp[m-1][n-1]=1;

    // Fill the bottom-most row and right-most column with 1s
    for(int i = 0; i < m; i++) dp[i][n-1] = 1;
    for(int j = 0; j < n; j++) dp[m-1][j] = 1;
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    return dp[0][0];
}
int main(){
  
    return 0;
}