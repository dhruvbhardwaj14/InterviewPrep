#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.*/
/*Approach- 
instead of adding a coin like previous and finding min just find ways and count them
*/
// recursive
int getWays(int amount, vector<int>& coins,int idx){
    if(idx>=coins.size()){
        if(amount==0) return 1;
        return 0;
    }
    int take=0;
    if(amount>=coins[idx]) take=getWays(amount-coins[idx],coins,idx);
    int notTake=getWays(amount,coins,idx+1);
    return take+notTake;
}
int change(int amount, vector<int>& coins) {
    return getWays(amount,coins,0);
}

// memoization
int getWays(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp) {
    if (amount == 0) return 1;
    if (idx == coins.size()) return 0;
    if (dp[idx][amount] != -1) return dp[idx][amount];

    int take = 0;
    if (coins[idx] <= amount)
        take = getWays(amount - coins[idx], coins, idx, dp); // stay at same idx
    int notTake = getWays(amount, coins, idx + 1, dp); // move to next idx

    return dp[idx][amount] = take + notTake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return getWays(amount, coins, 0, dp);
}

int main(){
  
    return 0;
}