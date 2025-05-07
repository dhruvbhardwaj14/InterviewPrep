#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
*/
/*Approach- 
1. to know the shape and keep it in mind what we can do is select a base coordinate and go in same direction for each of the bases in our code and subtract the current coordinates from the base and push them into the vector for shapes(vec)
2. for each disconnected component do same and make a vector and push these vectors to set of vectors(s)
3. return size of s gives distinct island to us.
*/
void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& grid,vector<pair<int,int>>& vec,int baseRow,int baseCol,int m,int n){
    vis[r][c]=1;
    vec.push_back({r-baseRow,c-baseCol});
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int nr=r+drow[i];
        int nc=c+dcol[i]; 
        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0){
            dfs(nr,nc,vis,grid,vec,baseRow,baseCol,m,n);
            
        }
        }
    
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    queue<pair<int,int>> q;
    set<vector<pair<int,int>>> s;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]&&grid[i][j]==1){
                vector<pair<int,int>> vec;
                dfs(i,j,vis,grid,vec,i,j,m,n);
                s.insert(vec);
            }
        }
    }
    return s.size();

    
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
    cout<<countDistinctIslands(grid)<<endl;
    return 0;
}