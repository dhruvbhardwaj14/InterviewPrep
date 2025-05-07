#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.


*/
/*Approach- 
1. Take all O's that are at edges that is 0th row 0th col n-1th col and m-1th row
2. run DFS for each of neighbors of O in grid which are not visited and are O itself and mark them visited during DFS
3. once all marked visit the visited array and for corresponding visited array mark as X for O in board which are not visited in Visited Array 

*/
void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>& vis,int m,int n){
    vis[i][j]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int r=drow[k]+i;
        int c=dcol[k]+j;
        if(r>=0 && r<m && c>=0 && c<n && board[r][c]=='O' && vis[r][c]==0){
            dfs(board,r,c,vis,m,n);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int m=board.size();
    int n=board[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==m-1 || j==n-1){
                if(board[i][j]=='O'){
                    dfs(board,i,j,vis,m,n);
                }
            }
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //             cout<<vis[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>> board(m,vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>board[i][j];
        }
    }
    solve(board);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}