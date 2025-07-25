#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top
*/
/*Approach- 
similar to fibonacci
if u at index I then u can reach to 0 by n-1 or n-2 and since count is said so just add them
*/
int countStairs(int n,vector<int>& dp){
        if(n<=1){
            dp[n]=n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=countStairs(n-1,dp)+countStairs(n-2,dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return countStairs(n,dp);
}
int main(){
  
    return 0;
}