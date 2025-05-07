#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.*/
/*Approach- 
- detecting using BFS 
- go on each child node and check if it is visited already but it is not equal to it's parent then definitely it's a cycle
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
bool bfs(int vertex,int parent,vector<vector<int>>& adj,vector<bool>& vis){
    queue<pair<int,int>> q;
    vis[vertex]=true;
    q.push({vertex,parent});
    while (!q.empty())
    {
        int cur_vex=q.front().first;
        int cur_par=q.front().second;   
        q.pop();
        for(int child:adj[cur_vex]){
            if(!vis[child]){
                vis[child]=true;
                q.push({child,cur_vex});
            }
            else if(cur_par!=child) return true; //it is visited already but it is not equal to it's parent then definitely it's a cycle
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj=buildGraph(edges,V);
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(bfs(i,-1,adj,vis)) return true;
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