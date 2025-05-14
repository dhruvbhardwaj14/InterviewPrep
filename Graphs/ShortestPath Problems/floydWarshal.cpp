#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Find shortest path from every node to every other node
You are given an weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 10^8) to represent infinity.
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j in the graph.

Note: Modify the distances for every pair in place.
*/
/*Approach- 
-multisource shortest path algorithm
-helps detect negative cycles as well
-use adjacency matrix representation
-dp solution
Q. how to detect negative weight cycle
Ans. in a negative weight cycle the costing of [0][0](0 to 0) will decrease from value 0 to some -ve which is not possible hence cycles
algo:- Go via every vertex from i.e. src to dest go via every vertex.
*/
void floydWarshall(vector<vector<int>> &dist) {
    int n=dist.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dist[i][j]==-1) dist[i][j]=1e9;
            if(i==j) dist[i][j]=0;
        }
        
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k]!=1e8 && dist[k][j]!=1e8)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        //negative weight cycle exist 
        if(dist[i][i]<0) cout<<"negative weight cycle"<<endl;
    }
    


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dist[i][j]==1e9) dist[i][j]=-1;
        }
        
    }
    
    
}
int main(){
  
    return 0;
}