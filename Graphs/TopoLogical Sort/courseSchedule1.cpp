#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/
/*Approach- 
Apply kahn algorithms and check if topological ordering possible or not if yes then we can finish courses if not then we cannot
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
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj=buildGraph(numCourses,prerequisites);
    vector<int> indeg(numCourses,0);
    queue<int> q;
    int cnt=0;
    for(int i=0;i<numCourses;i++){
        for(auto node:adj[i]) indeg[node]++;
    }
    for(int i=0;i<numCourses;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
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
    return (cnt==numCourses);
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

    if (canFinish(numCourses, prerequisites)) {
        cout << "Yes, all courses can be finished." << endl;
    } else {
        cout << "No, it's not possible to finish all courses due to a cycle." << endl;
    }

    return 0;
}