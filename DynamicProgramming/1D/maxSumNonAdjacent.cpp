#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array arr containing positive integers. Find the maximum sum of elements of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr[].
*/
/*Approach-
1. First, understand the problem: you need to find the maximum sum of non-adjacent elements in a given array.
2. Think in terms of dynamic programming. At each index `i`, you have two choices:
   * Include the current element `arr[i]` and add it to the result till `i-2`.
   * Exclude the current element and take the result till `i-1`.
3. Create a dp array of size equal to the length of the input array.
4. Handle base cases:
   * If array size is 0, return 0.
   * If array size is 1, return `arr[0]`.
5. Initialize:
   * `dp[0] = arr[0]`
   * `dp[1] = max(arr[0], arr[1])`
6. Loop from index 2 to n-1:
   * For each index `i`, calculate `dp[i] = max(dp[i-1], arr[i] + dp[i-2])`
7. After the loop ends, `dp[n-1]` will hold the answer.
8. Return `dp[n-1]` as the final result.
*/

// recursive
// int getMax(vector<int>& arr, int idx) {
//     if (idx >= arr.size()) return 0;

//     // Option 1: Take current and skip next
//     int take = arr[idx] + getMax(arr, idx + 2);

//     // Option 2: Skip current
//     int notTake = getMax(arr, idx + 1);

//     return max(take, notTake);
// }

// int findMaxSum(vector<int>& arr) {
//     return getMax(arr, 0);
// }


// memoization
// int getMax(vector<int>& arr,vector<int>& dp, int idx) {
//     if (idx >= arr.size()) return 0;

//     if(dp[idx]!=-1) return dp[idx];
//     // Option 1: Take current and skip next
//    return dp[idx]=max((arr[idx] + getMax(arr,dp, idx + 2)),getMax(arr,dp,idx + 1));

    
// }

// int findMaxSum(vector<int>& arr) {
//     vector<int> dp(arr.size()+1,-1);
//     return getMax(arr,dp, 0);
// }


// Tabulation
int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    return dp[n - 1];
}

int main(){
  
    return 0;
}