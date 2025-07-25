#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.*/
/*Approach- 
The catch is the array is divided into two parts only.
so if sum of whole nums is odd(s)-> not possible to divide in 2
so if sum of whole nums is even(s)-> search if a subarray of sum==s/2 exist
->if yes then other is having sum s/2 return true
-> if no then no other is having sum s/2 return false
*/
bool isSum(vector<int>& nums,int sum){
    vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
    // Base Case: sum 0 is always possible (by taking no elements)
    for(int i = 0; i <=nums.size(); i++) {
        dp[i][0] = true;
    }
    for (int i = nums.size()-1; i>=0; i--)
    {
        for (int s = 0; s <= sum; s++)
        {
            bool notTake=dp[i+1][s];
            bool take=false;
            if(s>=nums[i]){
                take=dp[i+1][s-nums[i]];
            }
            dp[i][s]=take || notTake;
        }
    }
return dp[0][sum];
}
bool canPartition(vector<int>& nums) {
    int sum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum+=nums[i];
    }
    if(sum&1) return false;
    return isSum(nums,sum/2);
    
} 
int main(){
  
    return 0;
}