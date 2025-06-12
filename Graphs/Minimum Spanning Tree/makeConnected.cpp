#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*/
/*Approach- 
if i can figure out number of connected components(nc) then the answer will be nc-1 given that i have atleast nc-1 extra edges else the answer will be again -1;
*/
class DisjointSet{
    public:
    vector<int> rank,parent,size;
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
int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1) return -1;

    // count extra edges
    DisjointSet ds(n);
    int extraEdges=0;
    for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(!ds.isSameSet(u,v)){
            ds.UnionByRank(u,v);
        }
        else{
            extraEdges++;
        }
    }

    // count number of connected components
    int cntC=0;
    for (int i = 0; i < n; i++)
    {
        if(ds.parent[i]==i)cntC++;
    }
    int ans=cntC-1;
    if(extraEdges>=ans){
        return ans;
    }
    else return -1;
}
int main(){

    return 0;
}