#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
*/
/* Approach- 
modify and create graph for each edge whose either row or col matches
-create a disjoint set of rows from 0-n-1 and then disjoint set of col from n to 2n-1
- col are shifted mapped as colnum(0-n-1)+n-1+1
- traverse the given stones array and for each row and col combine their respective disjoint sets 
- if the parent[i]==i we get number of connected components 
answer is V-no. of connected components
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
int removeStones(vector<vector<int>>& stones) {
    int V=stones.size();
    int maxRow=0;
    int maxCol=0;
    for(auto it:stones){
        maxRow=max(maxRow,it[0]);
        maxCol=max(maxCol,it[1]);
    }

    DisjointSet ds(maxRow+maxCol+1);
    unordered_map<int,int> stoneNodes;
    for(auto it:stones){
        int nodeRow=it[0];
        int nodeCol=it[1]+maxRow+1;
        ds.UnionBySize(nodeRow,nodeCol);
        stoneNodes[nodeRow]=1;
        stoneNodes[nodeCol]=1;
    }
    int cnt=0;
    for(auto it:stoneNodes){
        if(ds.findUltimateParent(it.first)==it.first){
            cnt++;
        }
    }
    return V-cnt;
    
}
int main(){
  
    return 0;
}