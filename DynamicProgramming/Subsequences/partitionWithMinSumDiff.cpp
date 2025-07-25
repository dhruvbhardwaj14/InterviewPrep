#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
Return the minimum possible absolute difference.*/
/*Approach- 
If we check for a target==k to be possible with a subset or not by using tabulation method 
then the table fills the table for all the targets(from 1 to K) being possible or not with array of size n-1

that means the last row of table will tell you that from 0 to Sum which all possible values are there which are possible

1. Find all possible sums from 0 to Sum in our array that our possible -> s1(sum of first partition)
2. For all the possible s1 find corresponding s2(totalsum-s1) and check difference with s1 and find min of all
*/
int minimumDifference(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for (int i = 0; i <n ; i++)
    {
        sum+=nums[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    // if sum is zero then all indices it is possible
    for (int i = 0; i <=n; i++)
    {
        dp[i][0]=true;
    }
    // if first index equal to sum then arr[0] is answer;
    if(sum>=nums[0]) dp[0][nums[0]]=true;
    // tabulate the all sums that are possible
    for (int i = 1; i<n ; i++)
    {
        for (int s = 1; s <=sum; s++)
        {
            bool notTake=dp[i+1][s];
            bool take=false;
            if(s>=nums[i]) take=dp[i+1][s-nums[i]];
            dp[i][s]=take || notTake;
        }
    }
    // dp[n-1][sum] contains answer for sum 
    // last row will have all possible sums
    int mn=INT_MAX;
    for (int i = 0; i <=sum/2; i++)
    {
        if(dp[n-1][i]) {
            int s2=sum-i;
            mn=min(mn,abs(s2-i));
        }
    }
    return mn;
    
}
int main(){
  
    return 0;
}