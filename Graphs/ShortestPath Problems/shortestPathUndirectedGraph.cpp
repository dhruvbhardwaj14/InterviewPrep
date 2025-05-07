#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.*/
/*Approach -
1. Run BFS on graph
2. at each level increase the distance by 1.
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
vector<int> shortestPath(int source,vector<vector<int>>& edges,int V){
    vector<int> ans(V,-1);
    vector<vector<int>> adj=buildGraph(edges,V);
    vector<bool> vis(V,false);
    queue<pair<int,int>> q;
    q.push({source,0});
    vis[source]=true;
    ans[source]=0;
    while (!q.empty())
    {
        int curr=q.front().first;
        int dist=q.front().second;
        q.pop();
        for(auto child:adj[curr]){
            if(!vis[child]){
                vis[child]=true;
                q.push({child,dist+1});
                ans[child]=dist+1;
            }
        }
    }
    return ans;
    
}
int main(){
    int n,m,source;
    cin>>n>>m>>source;
    vector<vector<int>> edges(m,vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>edges[i][j];
        }
    }
    vector<int> ans=shortestPath(source,edges,n);
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}