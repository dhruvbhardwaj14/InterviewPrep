#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/
/*Approach-
1.Use kahn's algorithm like the way we used it in previous part and here instead of count increase we add the element to the ans vector which in fact is the topological ordering of our elements and return ans if it's size is equal to numCourses that means there is no cycle
*/
vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> adj(numCourses);
    for(auto course:prerequisites){
        int a=course[0];
        int b=course[1];
        adj[b].push_back(a);
    }
    return adj;
};
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj=buildGraph(numCourses,prerequisites);
    vector<int> indeg(numCourses,0);
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        for(auto node:adj[i]) indeg[node]++;
    }
    for (int i = 0; i < numCourses; i++)
    {
        if(indeg[i]==0) q.push(i);
    }
    while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        ans.push_back(curr);
        for(auto child:adj[curr]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    
    if(ans.size()!=numCourses) ans.clear();
    return ans;
}
int main(){
    int numCourses, m;
    cin >> numCourses >> m;

    vector<vector<int>> prerequisites;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        prerequisites.push_back({a, b});
    }

    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course order (cycle detected)." << endl;
    } else {
        cout << "Valid course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}