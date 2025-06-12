#include "bits/stdc++.h"
using namespace std;
//Problem Statement

/*
Implement Prim's algo to solve it
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.*/
/*Approach- 
the priority queue contains:-
1. if mst is also asked (wt,node,parent)
2. if only sum of mst asked (wt,node)

1.If mst also asked
-push {0,0,-1}(wt,node,parent) into the queue and start the loop
-if node is already visited go to next iteration
-if node is not visited mark it as visited (before going into adjacency of node) and if parent!=-1 add node and parent to ans vector
-then go to adjacency of the node and push the edges to priority queue


2. only sum asked
-push {0,0}(wt,node) into the queue and start the loop
-if node is already visited go to next iteration
-if node is not visited mark it as visited (before going into adjacency of node) add wt to sum;
-then go to adjacency of the node and push the edges to priority queue
*/

// Function to find sum of weights of edges of the Minimum Spanning Tree.
vector<pair<int,int>> printSpanningTree(int V,vector<vector<int>> adj[]){
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    vector<int> vis(V,0);
    vector<pair<int,int>> ans;//stores edges of MST
    pq.push({{0,0},-1});
    while(!pq.empty()){
        int wt=pq.top().first.first;
        int node=pq.top().first.second;
        int parent=pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
        if (parent != -1)
            ans.push_back({parent, node});
        for(auto child:adj[node]){
            int adjNode=child[0];
            int ed_wt=child[1];
            int adj_par=node;
            if(!vis[adjNode]){
                pq.push({{ed_wt,adjNode},adj_par});
            }
        }
    }
    return ans;
}
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
        sum+=wt;
        for(auto child:adj[node]){
            int adjNode=child[0];
            int ed_wt=child[1];
            if(!vis[adjNode]){
                pq.push({ed_wt,adjNode});
            }
        }
    }
    return sum;
}
int main(){
    /*These two lines:
     Speed up your input/output significantly.
     Safe to use in competitive programming, as long as you don't mix C-style and C++-style I/O.
    */
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since undirected
    }

    int mstCost = spanningTree(V, adj);
    cout << "Total weight of MST: " << mstCost << '\n';

    vector<pair<int, int>> mstEdges = printSpanningTree(V, adj);
    cout << "Edges in MST:\n";
    for (auto &edge : mstEdges) {
        cout << edge.first << " - " << edge.second << '\n';
    }
    return 0;
}