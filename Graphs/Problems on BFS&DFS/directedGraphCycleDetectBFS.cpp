#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Detect cycle in a directed graph using BFS*/
/*Approach- 
There is no direct approach but what we can do is use Kahn's algorithm and try generating a topological ordering and if it does not come out to be equal to size of number of vertices then there is a cycle. 

*/
bool isCyclic(int n,vector<vector<int>>& adj){
   vector<int> indeg(n,0);
   queue<int> q; 
   int cnt=0;
   for (int i = 0; i < n; i++)
   {
        for(auto node:adj[i]) indeg[node]++;
   }
   for (int i = 0; i < n; i++)
   {
        if(indeg[i]==0){
            q.push(i);
        }
   }
   while (!q.empty())
   {
        int curr=q.front();
        q.pop();
        cnt++;
        for(auto child:adj[curr]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
   }
   if(cnt==n) return false;
   else return true;
   
   
   
}
int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed graph
    }

    if (isCyclic(n, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}