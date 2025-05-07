#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

*/
/*Approach- 
1. run normal dijkstra
2. create a ways array that means whenever a weight is updated then it takes the number of ways it's parents has come to this weight only assigned since weight updated may or may not be minimum;
3. but as soon as weight is same as current weight add the number of ways to the current meaning that total ways we are finding out.
4. return ways[n-1]; at end
*/
int countPaths(int n, vector<vector<int>>& roads) {
    int modulo=1e9+7;
    vector<vector<pair<int,int>>> adj(n);
    for(auto road:roads){
    int u=road[0]; 
    int v=road[1]; 
    int t=road[2]; 
    adj[u].push_back({v,t});
    adj[v].push_back({u,t});
    }
    vector<int> time(n,INT_MAX);
    vector<int> ways(n,0);
    int src=0;
    int dest=n-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0, src}); // <time, node>
    time[src] = 0;
    ways[src] = 1;

    while(!q.empty()) {
        int t_node = q.top().first; // Time taken to reach this node
        int node = q.top().second;  // The node itself
        q.pop();

        for(auto child : adj[node]) {
            int v = child.first;
            int edge_time = child.second;
            long long new_time = 1LL * t_node + edge_time;
            if(new_time < time[v]) {
                time[v] = t_node + edge_time;
                ways[v] = ways[node];
                q.push({time[v], v});
            }
            else if(new_time  == time[v]) {
                ways[v] = (ways[v] + ways[node]) % modulo;
            }
        }
    }
    return ways[n-1]%modulo;
}
int main(){
  
    return 0;
}