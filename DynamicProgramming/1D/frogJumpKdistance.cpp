#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
N frogs are positioned at one end of the pond. All frogs want to reach the other end of the pond as soon as possible. The pond has some leaves arranged in a straight line. Each frog has the strength to jump exactly K leaves. For example, a  frog having strength 2 will visit the leaves 2, 4, 6, ...  etc. while crossing the pond.
Given the strength of each frog and the number of leaves, your task is to find the number of leaves that not be visited by any of the frogs when all frogs have reached the other end of the pond. */
/*
Approach- 
1. make a visited vector which keeps count of wheter a leaf is visited by a frog or not
2. make an unordered_set since it's access time is O(1) average case
3. now whenever we reach a strength of frog from it's array we check first that did we already mark it in the array before or not using usedStrength.count(k)-> returns true if value exist in map and false if not
4. if check is failed then we mark visited all multiples of that leaf
*/
int unvisitedLeaves(int N, int leaves, int frogs[]) {
    vector<bool> visited(leaves + 1, false);
    unordered_set<int> usedStrength;

    for (int i = 0; i < N; i++) {
        int k = frogs[i];
        if (k == 0 || k > leaves || usedStrength.count(k)) continue; // Skip invalid or duplicate strengths
        usedStrength.insert(k);

        for (int j = k; j <= leaves; j += k) {
            visited[j] = true;
        }
    }

    int unvisited = 0;
    for (int i = 1; i <= leaves; i++) {
        if (!visited[i]) unvisited++;
    }

    return unvisited;
}
int main(){

    return 0;
}
