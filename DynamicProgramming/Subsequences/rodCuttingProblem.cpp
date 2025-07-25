#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.*/
/*Approach-
Sure Dhruv! Here's the **Rod Cutting Problem – Tabulation (Bottom-Up DP) Approach** in **pure plain text** with complete logic, no formatting:

---

Rod Cutting Problem (Tabulation Approach)

Problem:
You are given a rod of length n and a 1-indexed array price\[] of size n. Each price\[i] represents the price of a rod piece of length i+1. Your task is to find the maximum price you can get by cutting the rod into pieces of any length and selling them.

Approach:
State Definition:
Let dp\[i]\[length] be the maximum price obtainable using the first (i+1) piece sizes to fill a rod of total length "length".

Base Case:
When i = 0, you are only allowed to use pieces of length 1. To form a rod of any length "len", you will take only 1-length pieces. So:
dp\[0]\[len] = len \* price\[0]

Transition:
For every piece index i from 1 to n-1
For every rod length len from 0 to n
You have two choices:
1\. Not take the current piece (length i+1): dp\[i]\[len] = dp\[i-1]\[len]
2\. Take the current piece (if its length <= len): dp\[i]\[len] = price\[i] + dp\[i]\[len - (i+1)]
Take the maximum of these two choices:
dp\[i]\[len] = max(dp\[i-1]\[len], price\[i] + dp\[i]\[len - (i+1)]) if i+1 <= len

Final Answer:
After filling the table, the maximum obtainable price will be stored in dp\[n-1]\[n]

Time Complexity:
O(n \* n) because we loop over n piece sizes and n rod lengths

Space Complexity:
O(n \* n) due to the 2D dp table. This can be optimized to O(n) using a single 1D array.

Analogy:
This is similar to the unbounded knapsack problem, where you are allowed to take the same piece size multiple times to reach the target rod length.
*/
// recursive
int solveRecursive(int idx, int n, vector<int>& price) {
    if (idx == 0) return n * price[0]; // Only 1-length pieces can be used

    int notTake = solveRecursive(idx - 1, n, price);
    int take = INT_MIN;
    int rodLength = idx + 1;
    if (rodLength <= n) {
        take = price[idx] + solveRecursive(idx, n - rodLength, price);
    }

    return max(take, notTake);
}

int cutRod(vector<int> &price) {
    int n = price.size();
    return solveRecursive(n - 1, n, price);
}
// memoization
int solveMemo(int idx, int n, vector<int>& price, vector<vector<int>>& dp) {
    if (idx == 0) return n * price[0];
    if (dp[idx][n] != -1) return dp[idx][n];

    int notTake = solveMemo(idx - 1, n, price, dp);
    int take = INT_MIN;
    int rodLength = idx + 1;
    if (rodLength <= n) {
        take = price[idx] + solveMemo(idx, n - rodLength, price, dp);
    }

    return dp[idx][n] = max(take, notTake);
}

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveMemo(n - 1, n, price, dp);
}
// tabulation
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base case: only 1-length cuts
    for (int len = 0; len <= n; ++len) {
        dp[0][len] = len * price[0];
    }

    for (int idx = 1; idx < n; ++idx) {
        for (int len = 0; len <= n; ++len) {
            int notTake = dp[idx - 1][len];
            int take = INT_MIN;
            int rodLength = idx + 1;
            if (rodLength <= len) {
                take = price[idx] + dp[idx][len - rodLength];
            }
            dp[idx][len] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

int main(){
  
    return 0;
}