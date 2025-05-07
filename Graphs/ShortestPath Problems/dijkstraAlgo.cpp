#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.*/

/*Approach- 
This approach takes more time than topological sort approach in previous QUES in DAG

1. Can be implemented using Priority Queue - O(ElogV)
2. Can be implemeneted using Set as well - O()


Priority queue implementation.(min heap)
-DEFAULT MAX HEAP
    priority_queue<pair<int, int>> pq;
-Min-Heap — Smallest pair at top:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

Algorithm
- store in format {node,dist}
- everytime the distance is updated in the dist[] add it to the priority queue
- each time when all neighbours are over for a node u select minimum from priority queue and take it's neighbours and relax the edges and repeate step 2

Why priority QUEUE?


Set implementation.(Stores everything in ascending order itself)
-- store in format {node,dist}
-- can erase already existing paths and not add them back in if got a minimum distance for a node


*/

// Priority Queue Implementation
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<bool> vis(V,false);
    vector<int> dist(V,INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({src,0});
    dist[src]=0;
    while (!pq.empty())
    {
        int node=pq.top().first;
        int di=pq.top().second;
        pq.pop();
        for(auto child:adj[node]){
            int v=child.first;
            int edge_Wt=child.second;
            if(di+edge_Wt<dist[v]){
                dist[v]=di+edge_Wt;
                pq.push({v,dist[v]});
            }
        }
    }
    return dist;
}
// Set Implementation
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<bool> vis(V,false);
    vector<int> dist(V,INT_MAX);
    set<pair<int,int>> s;
    s.insert({src,0});
    dist[src]=0;
    while (!s.empty())
    {
        auto it=*(s.begin());
        int node=it.first;
        int di=it.second;
        s.erase(it);
        for(auto child:adj[node]){
            int v=child.first;
            int edge_Wt=child.second;
            if(di+edge_Wt<dist[v]){
                // erase if it existed
                if(dist[v]!=INT_MAX) s.erase({v,dist[v]});
                dist[v]=di+edge_Wt;
                s.insert({v,dist[v]});
            }
        }
    }
    return dist;
}
int main(){
  
    return 0;
}