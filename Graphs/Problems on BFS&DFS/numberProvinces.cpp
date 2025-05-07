#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
/*Approach- 
n- vertices of graph
1. we will transform the matrix in a adjacency list graph where for each cell matrix[i][j] we make an edge from i to j in adj since we traverse whole matrix thus an edge from i to j and j to i will itself be created in whole traversal
2. Run dfs on each vertex for connected component and each time a new component is found just increase the answer as a province
*/
vector<vector<int>> buildGraph(vector<vector<int>>& isConnected,int n){
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++ ){
        for (int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    return adj;
}
void dfs(int vertex,vector<bool>& visited,vector<vector<int>>& adj,int& ans){
    visited[vertex]=true;
    for(auto child:adj[vertex]){
        if(!visited[child]){
            dfs(child,visited,adj,ans);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<vector<int>> adj=buildGraph(isConnected,n);
    int ans=0;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,adj,ans);
            ans++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> isConnected[i][j];
        }
    }

    int provinces = findCircleNum(isConnected);

    return 0;
}