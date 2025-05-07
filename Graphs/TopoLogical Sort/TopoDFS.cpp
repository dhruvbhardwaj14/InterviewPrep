#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement Topological sorting using DFS */
/*Approach-
USING DFS WE IMPLEMENT IT.
- it only exists on DIrected Acyclic Graph(DAG)
-any linear ordering of nodes of directed graph such that if there is an edge between u and v. 'u' appears before 'v' in that ordering

if there is edge from u to v then it means v is dependent on u (u->v)

1.Dfs can go as deep as possbile that means dfs will always reach the node which is completely dependent on previous node but no nodes is dependent on it hence it is pushed first into the stack that means it will be last in our ordering.
2, so we keep repeating dfs and at the end print stack from the top
*/
void dfs(int i,vector<vector<int>>& adj,vector<int>& vis,stack<int>& s){
    vis[i]=1;
    for(auto child:adj[i]){
        if(!vis[child]){
            dfs(child,adj,vis,s);
        }
    }
    s.push(i);
}
vector<int> TopologicalOrdering(int v,vector<vector<int>>& adj){
    vector<int> vis(v,0);
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,adj,vis,s);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for (int i = 0; i < e; i++) {
        int u, vtx;
        cin >> u >> vtx;
        adj[u].push_back(vtx);  // Directed edge
    }

    vector<int> topo = TopologicalOrdering(v, adj);

    cout << "Topological Ordering:\n";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}