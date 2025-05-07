#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Detect cycle in directed graph*/
/*Approach- 
1. along with a visited array make a path visited array that means as soon as we go deep in dfs the path visited is 1 and as soon as we return back and back track to nodes then path visited is 0
2. so if any node is visited but has already been back tracked that means it's not a cycle since it's pathvisited is 0
3. else there is a cycle and we output true

*/
bool dfs(int i,vector<int>& vis,vector<int>& pathVis,vector<vector<int>>& adj){
    vis[i]=1;
    pathVis[i]=1;
    for(auto child:adj[i]){
        //when node not visited
        if(!vis[child]){
            if(dfs(child,vis,pathVis,adj)==true) return true;
        }
        //if node previously visited but it has to be on same path
        else if(pathVis[child]){
            return true;
        }
    }
    //when going back  make sure to make pathVis false .
    pathVis[i]=0;
    return false;
}
bool isCyclic(int n,vector<vector<int>>& adj){
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,pathVis,adj)==true) return true;
        }
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed graph
    }

    if (isCyclic(n, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}