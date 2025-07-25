#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/
/*Approach- 
1. Understand the problem: you are given a list of non-negative integers representing the amount of money in each house; you need to find the maximum amount you can rob without robbing two adjacent houses.
2. Think in terms of dynamic programming. At each house `i`, you have two choices:

   * Rob the house: add `nums[i]` to the max amount till `i-2`.
   * Skip the house: take the max amount till `i-1`.

3. Handle base cases:

   * If the array is empty, return 0.
   * If there is only one house, return `nums[0]`.

4. Create a dp array of size `n + 2` initialized with 0 to avoid out-of-bounds.

5. Initialize:

   * `dp[0] = nums[0]`
   * `dp[1] = max(nums[0], nums[1])`

6. Loop from index 2 to n - 1:

   * For each index `i`, calculate `dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])`

7. After the loop ends, `dp[n - 1]` contains the final answer.

8. Return `dp[n - 1]` as the result.

*/
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    vector<int> dp(n+2,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1]; 
}
int main(){
  
    return 0;
}