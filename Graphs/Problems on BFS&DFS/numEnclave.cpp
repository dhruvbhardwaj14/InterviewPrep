#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.s
*/
/*Approach-
1. Take all 1's that are at edges that is 0th row 0th col n-1th col and m-1th row
2. run DFS for each of neighbors of 1 in grid which are not visited and are 1 itself and mark them visited during DFS
3. once all marked visit the visited array and for corresponding visited array increase coun of 1's in board which are not visited in Visited Array 
*/
void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,int m,int n){
    vis[i][j]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int r=i+drow[k];
        int c=j+dcol[k];
        if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1 && vis[r][c]==0){
            dfs(grid,vis,r,c,m,n);
        }
    }

}
int numEnclaves(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==m-1 || j==n-1){
                if(grid[i][j]==1)
                dfs(grid,vis,i,j,m,n);
            }
        }
    }
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                count++;
            }
        }
    }
    return count;

}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<numEnclaves(grid)<<endl;;
    
    return 0;
}