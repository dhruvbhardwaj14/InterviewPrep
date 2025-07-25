#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/**/
/*Approach- 
take and not take approach and add both 
*/
// recursive
int cntSubset(vector<int>& arr, int target,int idx){
    if(idx>=arr.size()) {
        if(target==0) return 1;
        return 0;
    }
    int left=cntSubset(arr,target-arr[idx],idx+1);
    int right=cntSubset(arr,target,idx+1);
    return left+right;
}
int perfectSum(vector<int>& arr, int target) {
    return cntSubset(arr,target,0);
}
// memoization
int cntSubset(vector<int>& arr, int target,int idx,vector<vector<int>>& dp){
    if(idx>=arr.size()) {
        if(target==0) return 1;
        return 0;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int take = 0;
    if (arr[idx] <= target)
        take = cntSubset(arr, target - arr[idx], idx + 1, dp);

    int notTake = cntSubset(arr, target, idx + 1, dp);

    return dp[idx][target] = take + notTake;
}
int perfectSum(vector<int>& arr, int target) {
    vector<vector<int>> dp(arr.size()+1,vector<int>(target+1,-1));
    return cntSubset(arr,target,0,dp);
}
// tabulation
int perfectSum(vector<int>& arr, int target) {
    int n=arr.size();
    vector<vector<int>> dp(arr.size()+1,vector<int>(target+1,0));
    dp[n][0]=1;
    for (int i = n-1; i >=0; i--)
    {
        for (int s = 0; s <=target; s++)
        {
            int take=0;
            if(arr[i]<=s){
                take=dp[i+1][s-arr[i]];
            }
            int notTake=dp[i+1][s];
            dp[i][s]=take+notTake;
        }
        
    }
    return dp[0][target];
}
int main(){
  
    return 0;
}