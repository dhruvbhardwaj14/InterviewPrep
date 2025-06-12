#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement Disjoint set*/
/*Approach-
We will create our own dataStructure DisjointSet
-DYNAMIC GRAPHS(grpahs changing configuration)- During formation of graph if not all edges are yet connected and in between someone asks us any question related to that particular unfinished graph and later on the graph changes by adding up 1 or 2 edges to the graph then we say that the graph is DYNAMIC

Disjoint sets gives us two functionalities in DYNAMIC GRAPHS(grpahs changing configuration)
1. Find parent
2. UNION - by size, by rank

UNION BY RANk - (O(4*alpha) - mathematically derived) ~ O(constant)
1. Create two arrays
 - Parent array where initially all nodes are disconnected so they are their own parent
 - Rank array which is initially 0 for all the nodes but as soon as we join two nodes by union we will update their ranks

 ALgo:- Union of (u,v)
 1. Find ultimate parent of u and v as pu and pv
 2.find rank of pu and pv
 3.connect smaller rank to bigger rank node and change it's parent to ulitmate parent


UNION BY Size - (O(4*alpha) - mathematically derived) ~ O(constant)
1. Create two arrays
 - Parent array where initially all nodes are disconnected so they are their own parent
 - Size array which is initially 1 for all the nodes but as soon as we join two nodes by union we will update their size by adding smaller size to bigger one

 ALgo:- Union of (u,v)
 1. Find ultimate parent of u and v as pu and pv
 2.find size of pu and pv
 3.connect smaller size to bigger size node and change it's parent to ulitmate parent and add it's size to bigger size
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
int main(){
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    //if 3 and 7 belong to same set oR not?
    if(ds.isSameSet(3,7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    ds.UnionBySize(3,7);
    if(ds.isSameSet(3,7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    // DisjointSet ds(7);
    // ds.UnionByRank(1,2);
    // ds.UnionByRank(2,3);
    // ds.UnionByRank(4,5);
    // ds.UnionByRank(6,7);
    // ds.UnionByRank(5,6);
    // //if 3 and 7 belong to same set oR not?
    // if(ds.isSameSet(3,7)){
    //     cout<<"Same"<<endl;
    // }
    // else{
    //     cout<<"Not Same"<<endl;
    // }
    // ds.UnionByRank(3,7);
    // if(ds.isSameSet(3,7)){
    //     cout<<"Same"<<endl;
    // }
    // else{
    //     cout<<"Not Same"<<endl;
    // }
    return 0;
}