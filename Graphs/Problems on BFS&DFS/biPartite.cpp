#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/
/*
Approach - 
1. create a color array and initialise with -1 having all indices for all number of nodes that is 0 to n-1
2. now run dfs for each uncoloured node
3. in dfs 
-change the color to currCOlor which is either 0 or 1
-go into neighbours of graph and check that 
--if any child is uncoloured then go for dfs again and see it is false then return false
--if any child is coloured then check it's color if it matches current color that means it's a adjacent node with same colour hence graph cannot be bipartite hence return false
-if everything is fine return true;
*/
bool dfs(int i,vector<vector<int>>& graph,vector<int>& color,int currColor){
    color[i]=currColor;
    for(auto edge:graph[i]){
        if(color[edge]==-1){
        if(dfs(edge,graph,color,!currColor)==false) return false;
        }
        else if (color[edge]==currColor){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> color(n,-1);  
    int currColor=0; 
    for(int i=0;i<n;i++){
        if(color[i]==-1)
        if(!dfs(i,graph,color,currColor)) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n; // Number of nodes
    vector<vector<int>> graph(n);

    for(int i = 0; i < n; i++){
        int m;
        cin >> m; // Number of edges for node i
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    if(isBipartite(graph))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is Not Bipartite" << endl;
    return 0;
}