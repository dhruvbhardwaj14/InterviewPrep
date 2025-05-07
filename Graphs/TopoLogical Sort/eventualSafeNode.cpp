#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

*/
/*Approach- 
1. Since a terminal node has outdeg 1 we can reverse the graph edges and start with all nodes of indeg 0 as they are terminal now and run Kahn's algo for topological sort and whatever nodes we get as ans will be our final answer
*/
vector<vector<int>> buildGraph(vector<vector<int>>& graph,int n){
    vector<vector<int>> adj(n);
    int i=0;
    for(auto arr:graph){
        for(auto node:arr){
            adj[node].push_back(i);
        }
        i++;
    }
    return adj;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    //reverse graph edges
    vector<vector<int>> adj=buildGraph(graph,n);
    //Run kahn's algo 
    vector<int> indeg(n,0);
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<n;i++){
        for(auto child:adj[i]){
            indeg[child]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans.push_back(curr);
        for(auto child:adj[curr]){
            indeg[child]--;
            if(indeg[child]==0) q.push(child);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k; // number of neighbors
        graph[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> safe = eventualSafeNodes(graph);

    for (int node : safe) {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}