#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/
/*Approach- 
1. {src,cost,stops}- store in this format and run dijkstra
*/
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto flight:flights){
        int u=flight[0];
        int v=flight[1];
        int cost=flight[2];
        adj[u].push_back({v,cost});
    }
   queue<pair<pair<int,int>,int>> pq;
    vector<int> dist(n,INT_MAX);
    pq.push({{src,0},0});
    dist[src]=0;
    while(!pq.empty()){
        int node=pq.front().first.first;
        int dist_node=pq.front().first.second;
        int stops=pq.front().second;
        if(stops>k){
            pq.pop();
            continue;
        }
        pq.pop();
        for(auto child:adj[node]){
            if(dist_node+child.second<dist[child.first] && stops<=k){
                dist[child.first]=dist_node+child.second;
                pq.push({{child.first,dist[child.first]},stops+1});
            }
        }
    }
    if(dist[dst]==INT_MAX) return -1;
    else return dist[dst];
}
int main(){
    int n,m,src,dst,k;
    cin>>n>>m>>src>>dst>>k;
    vector<vector<int>> flights(m,vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>flights[i][j];
        }
    }
    cout<<findCheapestPrice(n,flights,src,dst,k)<<endl;
    
    return 0;
}