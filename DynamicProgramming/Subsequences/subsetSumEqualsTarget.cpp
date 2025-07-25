#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 
*/
/*Approach- 
In memoization a 2d dp is used because idx and sum both are changing
*/
// recursion
bool getSum(vector<int>& arr, int sum,int idx){
    if(idx>=arr.size()){
        if(sum==0){
            return true;
        }
        return false;
    }
    return (getSum(arr,sum-arr[idx],idx+1)||getSum(arr,sum,idx+1));
} 
bool isSubsetSum(vector<int>& arr, int sum) {
    return getSum(arr,sum,0);
}
// memoization
bool getSum(vector<int>& arr, int sum,int idx,vector<vector<int>>& dp){
    if(sum == 0) return true;
    if(idx >= arr.size()) return false;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    bool take = false;
    if(arr[idx] <= sum)
        take = getSum(arr, sum - arr[idx], idx + 1, dp);
    bool notTake = getSum(arr, sum, idx + 1, dp);
    return dp[idx][sum] = take || notTake;
} 
bool isSubsetSum(vector<int>& arr, int sum) {
    vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
    return getSum(arr,sum,0,dp);

}
// tabulation
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base Case: sum 0 is always possible (by taking no elements)
    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for(int i = n - 1; i >= 0; i--) {
        for(int s = 0; s <= sum; s++) {
            bool notTake = dp[i + 1][s];
            bool take = false;
            if(s >= arr[i])
                take = dp[i + 1][s - arr[i]];
            dp[i][s] = take || notTake;
        }
    }

    return dp[0][sum];
}

int main(){
  
    return 0;
}