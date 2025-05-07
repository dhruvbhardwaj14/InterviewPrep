#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.*/

/*Approach- to check for all connected components and save them what we will do is we check for our visited array in our getcomponent function and for each time we encounter a unvisited node in that we create a component vector pass it to dfs function and push elements into it and then save all such components in result */
vector<vector<int>> BuildGraph(int V,vector<vector<int>>& edges){
    vector<vector<int>> adj(V);
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
void dfs(int vertex,vector<vector<int>>& adj,vector<int>& component,vector<bool>& visited){
    visited[vertex]=true;
    component.push_back(vertex);
    for(auto child:adj[vertex]){
        if(!visited[child]){
            dfs(child,adj,component,visited);
        }
    }
}
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj=BuildGraph(V,edges);
    vector<bool> visited(V,false);
    vector<vector<int>> res;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adj,component,visited);
            res.push_back(component);
        }
    }
    return res;
}
int main(){
     // Number of nodes in the graph
     int V = 5;

     // Edge list representing the undirected graph as vector of vectors
     vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
 
     // Get all connected components using the countComponents function
     vector<vector<int>> res = getComponents(V, edges);
 
     for (const auto& comp : res) {
         
         for (int node : comp) {
             cout << node << " ";
         }
         cout << "\n";
     }
     return 0;
}