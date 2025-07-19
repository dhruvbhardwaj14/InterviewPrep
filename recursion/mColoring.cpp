#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.
Note: The graph is indexed with 0-based indexing.*/

/*Approach- 
1. **Build adjacency list from edge list**
   * Initialize `adj[v]` where `v` is number of vertices.
   * For each edge `(u, v)`, push `v` to `adj[u]` and `u` to `adj[v]` (undirected graph).

2. **Define helper function `isSafe(node, color, adj, col)`**
   * For each neighbor of `node` in `adj[node]`:
     * If `color[neighbor] == col`, return `false` (conflict).
   * If no conflicts, return `true`.

3. **Define recursive function `canColor(node, color, m, v, adj)`**
   * Base case: If `node == v`, return `true` (all nodes colored).
   * Try all colors from `1` to `m`:
     * If `isSafe(node, color, adj, currentColor)` is `true`:
       * Assign `color[node] = currentColor`.
       * Recursively call `canColor(node + 1, color, m, v, adj)`.
       * If it returns `true`, propagate it.
       * Else, backtrack by setting `color[node] = 0`.

4. **In main function `graphColoring(v, edges, m)`**
   * Convert `edges` to an adjacency list.
   * Initialize `color` array of size `v` with all `0`s (uncolored).
   * Call `canColor(0, color, m, v, adj)`.
   * Return result (`true` if coloring is possible, else `false`).
*/
bool isSafe(int node, vector<int>& color, vector<vector<int>> &adj, int col) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == col) return false;
    }
    return true;
}

bool canColor(int node, vector<int>& color, int m, int n, vector<vector<int>> &adj) {
    if (node == n) return true;

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, adj, i)) {
            color[node] = i;
            if (canColor(node + 1, color, m, n, adj)) return true;
            color[node] = 0;
        }
    }

    return false;
}

bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    // Convert edge list to adjacency list
    vector<vector<int>> adj(v);
    for (auto &edge : edges) {
        int u = edge[0];
        int v2 = edge[1];
        adj[u].push_back(v2);
        adj[v2].push_back(u);
    }

    vector<int> color(v, 0);
    return canColor(0, color, m, v, adj);
}

int main(){
  
    return 0;
}