#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.*/
/*Approach- 
- detecting using DFS
- check if a  child node is already visited and it's not it's parent then return true for cycle else return false;
*/
vector<vector<int>> buildGraph(vector<vector<int>>& edges,int V){
    vector<vector<int>> adj(V);
    for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
    return adj;
}
bool dfs(int vertex,int parent,vector<vector<int>>& adj,vector<bool>& vis){
    vis[vertex]=true;
    for(auto child:adj[vertex]){
        if(!vis[child]) {
            if(dfs(child,vertex,adj,vis)) return true;
        }
        else if(child!=parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj=buildGraph(edges,V);
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)) return true;
        }
    }
    return false;
}
int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1}  // This edge introduces a cycle
    };

    if (isCycle(V, edges)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    return 0;
}