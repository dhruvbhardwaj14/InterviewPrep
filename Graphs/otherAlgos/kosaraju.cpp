#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*KOSARAJU ALGORITHM
Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.
*/
/*Approach-
Strongly connected components (DIRECTED GRAPHS ONLY)
ALGO:- 
1. Sort all the edges according to their finishing times (while backtracking from a node add it to the stack)
2. Reverse all the edges of graph
3. Do a dfs and store for each component in the main function
*/
void dfs(int source,vector<vector<int>> &adj,vector<int>& vis,stack<int>& s){
    vis[source]=1;
    for(auto child:adj[source]){
        if(!vis[child]){
            dfs(child,adj,vis,s);
        }
    }
    s.push(source);
}
void dfs3(int source,vector<vector<int>> &adj,vector<int>& vis){
    vis[source]=1;
    for(auto child:adj[source]){
        if(!vis[child]){
            dfs3(child,adj,vis);
        }
    }
}
int kosaraju(vector<vector<int>> &adj) {
    int v=adj.size();
    stack<int> s;
    vector<int> vis(v,0);
    // sort in order of finishing time in stack
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            dfs(i,adj,vis,s);
        }
    }
    // reverse the graph
    vector<vector<int>> reverseAdj(v);
    for (int i = 0; i < v; i++)
    {
        vis[i]=0;//mark unvisited again to be used again below
        for(auto it:adj[i]){
            reverseAdj[it].push_back(i);
        }
    }
    int scc=0;
    // traverse the reversed graph in order of stack
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!vis[node]){
            scc++;//strongly connected components number
            dfs3(node,reverseAdj,vis);
        }
    }
    return scc;
    
}
int main(){
  
    return 0;
}