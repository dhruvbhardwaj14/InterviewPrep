#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
*/
/*Approach s- 
1. create a graph of multiplication having 10^5 nodes in distance since it's modulo is done after each multiplication hence our end cannot be greater than that so i can have 0--99999 nodes in total in our tree where we start from src as step 0 multiply it by each element of array and reach next level of nodes then repeat until we get end and with end we will get it's level
2. run simple dijkstra
*/
int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start==end) return 0;
    int mod=100000;
    queue<pair<int,int>> q;
    vector<int> dist(mod,INT_MAX);
    q.push({0,start});
    dist[start]=0;
    while(!q.empty()){
        int step=q.front().first;
        int val=q.front().second;
        q.pop();
        for(int i=0;i<arr.size();i++){
            int ans=(val*arr[i])%mod;
            if(step+1<dist[ans]){
                dist[ans]=step+1;
                if(ans==end){
                    return step+1;
                }
                q.push({step+1,ans});
            }
        }
    }
    return -1;
}
int main(){
  
    return 0;
}