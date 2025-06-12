#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.*/
/*Approach- 
described in code belpw
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
int largestIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    DisjointSet ds(n*n);

    // connect all components
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]==0) continue; 
            int dr[]={1,0,-1,0};
            int dc[]={0,1,0,-1};
            for (int k = 0; k < 4; k++)
            {
                int nr=dr[k]+i;
                int nc=dc[k]+j;
                if(nr>=0 && nr<n && nc<n && nc>=0 && grid[nr][nc]==1){
                    int nodeNo=i*n+j;
                    int adjNodeNo=nr*n+nc;
                    ds.UnionBySize(nodeNo,adjNodeNo);
                }
            }
            
        }
        
    }
    // take every zero try converting to 1 check neighbouring components ulitmate and store in set and then sum their sizes in mx variable and store maximum of mx variable
    int mx=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]==1) continue;
            int dr[]={1,0,-1,0};
            int dc[]={0,1,0,-1};
            set<int> s;
            for (int k = 0; k < 4; k++)
            {
                int nr=dr[k]+i;
                int nc=dc[k]+j;
                if(nr>=0 && nr<n && nc<n && nc>=0 && grid[nr][nc]==1){
                    int adjNodeNo=nr*n+nc;
                    s.insert(ds.findUltimateParent(adjNodeNo));
                }
                int sum=0;
                for(auto it:s){
                    sum+=ds.size[it];
                }
                mx=max(sum+1,mx);//sum +1 because when zero connected to 1 will add one to the number of 1's
            }

        }
        
    }
    // if grid contains all 1's and no zeroes so mx should have max from ultimate parent of all nodes in the grid
    for (int i = 0; i < n*n; i++)
    {
        mx=max(mx,ds.size[ds.findUltimateParent(i)]);
    }
    return mx;
    
    
}
int main(){
  
    return 0;
}