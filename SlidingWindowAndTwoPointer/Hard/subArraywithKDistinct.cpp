#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/
/*Approach- 
1. Goal is to count subarrays with exactly k distinct integers.
2. Use the formula: exactlyK = atMostK(k) - atMostK(k - 1).
3. atMostK(k) counts subarrays with at most k distinct elements using a sliding window.
4. Expand the window by moving right pointer and updating the frequency map.
5. Shrink the window from the left if distinct elements exceed k, then add (r - l + 1) to the total count.

*/
int subarraysWithLessThanEqualKDistinct(vector<int>& nums, int k){
    int l=0,r=0,cnt=0;
    map<int,int> mp;
    while (r<nums.size())
    {
        mp[nums[r]]++;
        while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return(subarraysWithLessThanEqualKDistinct(nums,k)-subarraysWithLessThanEqualKDistinct(nums,k-1));
}
int main(){
  
    return 0;
}