#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex
*/
/*Approach- 
Why topological sort used?
topological sort uses the approach of least dependent node to it so if i have the least dependent node chosen first then compute relaxation of edges for it's edges later we can repeat the process for the next topologically least dependent nodes and hence all nodes before it would have already been computed successfully and we get our answer easly
*/
vector<vector<pair<int,int>>> buildGraph(vector<vector<int>>& edges,int V){
    vector<vector<pair<int,int>>> adj(V);
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adj[u].push_back({v,wt});
    }
    return adj;
}

//O(V+E);
void dfs(vector<vector<pair<int,int>>>& adj,vector<bool>& vis,stack<int>& s,int source){
   vis[source]=true;
   for(auto child:adj[source]){
       int curr_Child=child.first;
       if(!vis[curr_Child]){
           dfs(adj,vis,s,curr_Child);
       }
   }
   s.push(source);
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
   vector<vector<pair<int,int>>> adj=buildGraph(edges,V);
   stack<int> s;
   vector<bool> vis(V,false);
   vector<int> dist(V,INT_MAX);
   for(int i=0;i<V;i++){
       if(!vis[i]){
           dfs(adj,vis,s,i);
       }
   }

   //distance of source
   dist[0]=0;
   
//    O(V+E);
   while(!s.empty()){
       int curr=s.top();
       s.pop();
       if (dist[curr] != INT_MAX) {
            for (auto child : adj[curr]) {
                int v = child.first;
                int wt = child.second;
                if (dist[curr] + wt < dist[v]) {
                    dist[v] = dist[curr] + wt;
                }
            }
        }
   }
   vector<int> ans(V,-1);
    for(int i=0;i<V;i++){
        if(dist[i]!=INT_MAX){
            ans[i]=dist[i];
        }
    }
    return ans;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges(E,vector<int>(3));
    for (int i = 0; i < E; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>edges[i][j];
        }
    }
    vector<int> ans=shortestPath(V,E,edges);
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}