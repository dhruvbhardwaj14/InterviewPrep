#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/
/*
Approach-
1. Use dijkstra for shortest path as usual but as soon as u reach the destination node store the path length until now by the max of difference of absolute till now and find minimum of all such paths
*/
int minimumEffortPath(vector<vector<int>>& heights) {
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> q;
    pair<int,int> src={0,0};
    pair<int,int> destn={n-1,m-1};
    q.push({src,0});
    dis[src.first][src.second]=0;
    int drow[]={1,0,-1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty()){
        int r=q.top().first.first;
        int c=q.top().first.second;
        int diff=q.top().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m){
                int newEffort=max(abs(heights[nr][nc]-heights[r][c]),diff);
                if(newEffort<dis[nr][nc])
                {
                    dis[nr][nc]=newEffort;
                    q.push({{nr,nc},dis[nr][nc]});
                }
            }
        }
    }
    return dis[destn.first][destn.second];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> heights(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>heights[i][j];
        }
    }
    cout<<minimumEffortPath(heights)<<endl;
    return 0;
    return 0;
}