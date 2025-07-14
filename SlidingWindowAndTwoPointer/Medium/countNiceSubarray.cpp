#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.*/
/*Approach- 
1. Reimagine the subarray as a binary subarray with odd numbers as 1 and even as 0
2. Now find the binarySubarray with sum equal to k logic and it's done
*/
int findSumArraylessthan(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < nums.size()) {
        sum += nums[r];
        while (sum > goal) {
            sum -= nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> binArray(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            binArray[i]=nums[i]&1;
        }
        return(findSumArraylessthan(binArray,k)-findSumArraylessthan(binArray,k-1));
}
int main(){
  
    return 0;
}