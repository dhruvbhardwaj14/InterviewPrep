#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.
*/
/*Approach- Find cost of reaching from n-1 to 0 while base case is that cost of reaching from 0 to 0 is always 0
1. Take index from 0 to n-1
2. DO all stuffs on that index
3. take min of (all stuffs)
*/
// memoization
// int getCost(vector<int>& height,vector<int>& dp,int idx){
//     if(idx==0) return 0;
//     if(dp[idx]!=-1) return dp[idx];
//     int left=getCost(height,dp,idx-1)+abs(height[idx]-height[idx-1]);
//     int right=INT_MAX;
//     if(idx>1) right=getCost(height,dp,idx-2)+abs(height[idx]-height[idx-2]);
//     return dp[idx]=min(left,right);
// }

//  tabulation
// int minCost(vector<int>& height) {
//     int n=height.size();
//     vector<int> dp(n+1,-1);
//     // return getCost(height,dp,n-1);-> memoization
    

//     // 1. Define the DP array
//     // 2. Write the base case of memoization to tabulation format
//     dp[0]=0;//idx==0 return 0;
//     // 3. Run for loop from a to x where a is the last idx the recursion calls for and x is the first idx recursion started with in top down approach
//     for (int i = 1; i<n; i++)
//     {
//         // 4. Replace statements of recursion with function replaced by mere dp array 
//         int left=dp[i-1]+abs(height[i]-height[i-1]);
//         int right=INT_MAX;
//         if(i>1) right=dp[i-2]+abs(height[i]-height[i-2]);
//         dp[i]=min(left,right);
//     }
//     return dp[n-1]; 
// }

// optimised to space complexity 1
int minCost(vector<int>& height) {
    int n=height.size();
    // return getCost(height,dp,n-1);-> memoization
    
    // tabulation
    // 1. Define the DP array
    // 2. Write the base case of memoization to tabulation format
    int prev=0,prev_1=INT_MAX,curri=-1;//idx==0 return 0;
    // 3. Run for loop from a to x where a is the last idx the recursion calls for and x is the first idx recursion started with in top down approach
    for (int i = 1; i<n; i++)
    {
        // 4. Replace statements of recursion with function replaced by mere dp array 
        int left=prev+abs(height[i]-height[i-1]);
        int right=prev_1;
        if(i>1) right=prev_1+abs(height[i]-height[i-2]);
        curri=min(left,right);
        prev_1=prev;
        prev=curri;
    }
    return prev; 
}
int main(){
  
    return 0;
}