#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.*/

/*
Approach - 
1. Clear path means number of visited cells that means the src starts from 1 dist.alignas
2. Run dijkstra but in a maze like format handling all edge cases.
*/
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
    pair<int,int> src={0,0};
    pair<int,int> destn={n-1,n-1};
    if(grid[src.first][src.second]==1 || grid[destn.first][destn.second]==1) return -1;
    else{
        if(n==1) return 1;
    q.push({src,1});
    dis[src.first][src.second]=0;
    // 8 directional
    int drow[]={1,0,-1,0,1,-1,1,-1};
    int dcol[]={0,1,0,-1,1,1,-1,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dist+1<dis[nr][nc]){
                dis[nr][nc]=dist+1;
                if(nr==destn.first && nc==destn.second){
                    return dist+1;
                }
                q.push({{nr,nc},dist+1});
            }
        }
    }
    return -1;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}