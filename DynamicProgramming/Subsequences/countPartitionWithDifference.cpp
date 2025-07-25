#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 
*/
/*Approach- 
sum(S1) - sum(S2) = d        → (1)
sum(S1) + sum(S2) = T        → (2)
2 * sum(S1) = d + T
→ sum(S1) = (d + T)/2

Count the number of subsets whose sum is (d + totalSum)/2
*/
int countPartitions(vector<int>& arr, int d) {
    int n=arr.size();
    int tSum=0;
    for (int i = 0; i < arr.size(); i++)
    {
        tSum+=arr[i];
    }
    if((tSum+d)&1 || tSum<d) return 0;
    int target=(d+tSum)>>1;
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[n][0]=1;
    for (int i = n-1; i>=0; i--)
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