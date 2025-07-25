#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).*/

/*Approach- 

*/
// memoization
int getMinPath(vector<vector<int>>& matrix,int row,int col,int m,int n,vector<vector<int>>& dp){
    if (col < 0 || col >= n) return 1e9; // out of bounds
    if(row==m-1){
        return matrix[row][col];
    }
    if(dp[row][col]!=-1) return dp[row][col];
    int down = getMinPath(matrix, row + 1, col, m,n, dp);
    int rightDiag = getMinPath(matrix, row + 1, col + 1, m,n, dp);
    int leftDiag = getMinPath(matrix, row + 1, col - 1, m,n, dp);

    return dp[row][col] = matrix[row][col] + min(down, min(rightDiag,leftDiag));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return getMinPath(matrix,0,0,m,n,dp);
}
// tabulation
int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Start filling from the second-last row upward
    for (int row = m - 2; row >= 0; row--) {
        for (int col = 0; col < n; col++) {
            int down = matrix[row + 1][col];
            int leftDiag = (col > 0) ? matrix[row + 1][col - 1] : 1e9;
            int rightDiag = (col < n - 1) ? matrix[row + 1][col + 1] : 1e9;

            matrix[row][col] += min({down, leftDiag, rightDiag});
        }
    }

    // The answer is the minimum value in the first row
    return *min_element(matrix[0].begin(), matrix[0].end());
}

int main(){
  
    return 0;
}