#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/
/*Approach-
1. simple dijkstra approach
*/
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto time:times){
        int u=time[0];
        int v=time[1];
        int w=time[2];
        adj[u].push_back({v,w});
    }
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({k,0});
    dist[k]=0;
    while(!q.empty()){
        int node=q.top().first;
        int dist_node=q.top().second;
        for(auto child:adj[node]){
            int v=child.first;
            int edge_wt=child.second;
            if(dist_node+edge_wt<dist[v]){
                dist[v]=dist_node+edge_wt;
                q.push({v,dist[v]});
            }
        }
    }
    int ans=INT_MIN;;
    for (int i = 1; i <=n; i++)
    {
        if(dist[i]==INT_MAX){
            return -1;
        }
        ans=max(ans,dist[i]);
    }
    return ans;
}
int main(){
  
    return 0;
}