#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
*/
/*Approach- 
Find cnt of all subarrays with sum less than equal to goal
and also for subarrays with sum less than equal to goal-1 
subtract their answer and u will get for sum = goal
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
int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (findSumArraylessthan(nums,goal)-findSumArraylessthan(nums,goal-1));
}
int main(){
  
    return 0;
}