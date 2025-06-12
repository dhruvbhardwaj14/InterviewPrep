#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement Kruskal's algorithm*/
/*Approach- 
IT IS IMPLEMENTED USING DISJOINT SETS

ALGO:-
1. Sort all the edges (Wt,u,v) in accordance to their weights
2. for each edge in the data structure check if u and v belongs to same set or not using disjoint set property
-if yes discard
-if no add their weight to sum and add edge to mst
3. repeat untill the data structure is empty
*/
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i < n+1; i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);//path compression
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
       else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    bool isSameSet(int u,int v){
        if(findUltimateParent(u)==findUltimateParent(v)){
            return true;
        }
        else{
            return false;
        }
    }
};
vector<pair<int,int>> printSpanningTree(int V,vector<vector<int>> adj[]){
     //since we are given an adjacency list we convert it to edges of format(wt,u,v);
     vector<pair<int,pair<int,int>>> edges;
     for (int i = 0; i < V; i++)
     {
         for(auto it:adj[i]){
             int adjNode=it[0];
             int ed_wt=it[1];
             edges.push_back({ed_wt,{i,adjNode}});
         }
     }
     // Disjoint Set dataStructure
     DisjointSet ds(V);
     //sort the edges
     sort(edges.begin(),edges.end());
 
     //Data structure for answer
     vector<pair<int,int>> mst;
     for(auto it:edges){
         int wt=it.first;
         int u=it.second.first;
         int v=it.second.second;
 
         //if they are in same component(set) or not
         if(!ds.isSameSet(u,v)){
             //store answers
             mst.push_back({u,v});
             //union the nodes
             ds.UnionBySize(u,v);
         }
     }

     return mst;
}
int spanningTree(int V, vector<vector<int>> adj[]) {
    //since we are given an adjacency list we convert it to edges of format(wt,u,v);
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for(auto it:adj[i]){
            int adjNode=it[0];
            int ed_wt=it[1];
            edges.push_back({ed_wt,{i,adjNode}});
        }
    }
    // Disjoint Set dataStructure
    DisjointSet ds(V);
    //sort the edges
    sort(edges.begin(),edges.end());

    //Data structure for answer
    int mstWt=0;
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;

        //if they are in same component(set) or not
        if(!ds.isSameSet(u,v)){
            //store answers
            mstWt+=wt;
            //union the nodes
            ds.UnionBySize(u,v);
        }
    }

    return mstWt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*These two lines:
     Speed up your input/output significantly.
     Safe to use in competitive programming, as long as you don't mix C-style and C++-style I/O.
    */

    
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