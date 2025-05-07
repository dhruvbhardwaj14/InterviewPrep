#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/
/*Approach- 
1. make a visited grid that looks exactly like the original grid but with all values assigned to 0.
2. Run BFS but here the queue has i and j of all rotten oranges in start as a source with their time initialised as 0 and their respective values updated to 2 in visited grid.
3. whenever we are in loop of Queue we check that do we have valid "4-directionally adjacent " and if so we check it's value in grid and visited if it has value of 1 in grid that means it's a fresh orange and it's value in visited is not equal to 2 means it's not yet been updated by any of it's neighbours thus we push it with an extended time stamp to the queue  and make it rotten in the visited grid. hence our code uses BFS and solves the problem



*/
int orangesRotting(vector<vector<int>>& grid) {
    int n=grid[0].size();
    int m=grid.size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int tm=0;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return tm;
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
    cout<<orangesRotting(grid)<<endl;
    
    return 0;
}