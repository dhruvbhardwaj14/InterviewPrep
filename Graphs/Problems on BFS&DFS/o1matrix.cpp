#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.
*/
/*
Approach-  NEVER MISS POP function in BFS CODE
1. Create a visited array and queue which store coordinates i,j and distance d
2. for all initial 0 in matrix push them into queue their coordinates and their initial distance as 0;
3. for each of the member of q use drow and dcol and check if mat[i][j]==1 then update it with the current distance value from 0 let say d and add 1 so it becomes d+1 in visited array and then push this coordinates with ditance d+1 in queue and repeat for whole grid .
*/
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
            }
        }
    }
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]==1 && vis[nrow][ncol]==0){
                vis[nrow][ncol]=dist+1;
                q.push({{nrow,ncol},vis[nrow][ncol]});
            }
        }
    }
    return vis;
}
int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = updateMatrix(mat);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}