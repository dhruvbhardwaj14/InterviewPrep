#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

*/
/*Approach- 
-remember where i am coming from basically a parent array which stors when updated distance where exactly it came from
-create a path and return it
*/
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int> parent(n+1);
    for(int i=1;i<n+1;i++){
        parent[i]=i;
    }
    vector<bool> vis(n+1,false);
    vector<int> dist(n+1,INT_MAX);
    set<pair<int,int>> s;
    s.insert({1,0});
    dist[1]=0;
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
                parent[v]=node;
            }
        }
    }
    if(dist[n]==INT_MAX) return {-1}; 
    vector<int> path;
    path.push_back(dist[n]);
    int node=n;
    while (parent[node]!=node)
    {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin()+1,path.end());//so that weight is not reversed
    return path;
}
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<int> result = shortestPath(n, m, edges);

    if (result.size() == 1 && result[0] == -1) {
        cout << "No path exists from 1 to " << n << endl;
    } else {
        cout << "Shortest path from 1 to " << n << " is: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}