#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement Topological sorting using BFS*/
/*Approach-
USING BFS WE IMPLEMENT IT.
- it only exists on DIrected Acyclic Graph(DAG)
-any linear ordering of nodes of directed graph such that if there is an edge between u and v. 'u' appears before 'v' in that ordering

if there is an edge from u to v then it means v is dependent on u (u->v)

INDEGREE- no. of incoming edges to a node
how to find indegree of nodes?:-
(Traverse the adj list vector and and for each value in adj[u] say adj[u]={a,b,c} then increase indegree of a b and c by 1)

KAHN's Algorithm:-(use INDEGREE array)
1. insert all nodes in queue having indegree 0
2. take front of queue and add it to ans vector and move in adj of queue and decrease indegree of the adjacent nodes by 1.
3. as soon as we encounter any node whose indegree becomes 0 we push it to the queue and repeat untill queue is emptys
STEPS 1 2 and 3 follow bfs like approach but use indegree
*/
vector<int> TopologicalOrdering(int v,vector<vector<int>>& adj){
    vector<int> indeg(v,0);
    queue<int> q;
    vector<int> ans;
    //calc indegree of each node
    for(int i=0;i<v;i++){
        for(auto node:adj[i]){
            indeg[node]++;
        }
    }
    //push all initial 0 indeg nodes to queue
    for (int i = 0; i < indeg.size(); i++)
    {
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr=q.front();
        ans.push_back(curr);
        q.pop();
        for(auto child:adj[curr]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
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