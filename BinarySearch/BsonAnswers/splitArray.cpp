#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
*/
/*Approach- 
1. mid- denotes the sum of the array in range max to sum of arr
2. for each mid check if how many subarrays can be formed
3. if subarrays formed are lesser than required that means we need to minimize mid so hi=mid-1 and store ans
4. else move lo=mid+1 and repeat
*/
int countSub(vector<int>& nums, int mid){
    int sb=1,sm=0;
    for(int i=0;i<nums.size();i++){
        if(sm+nums[i]<=mid){
            sm+=nums[i];
        }
        else{
            sm=nums[i];
            sb++;
        }
    }
    return sb;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int lo=*max_element(nums.begin(),nums.end());
        int hi=accumulate(nums.begin(),nums.end(),0),ans=0;
        while(lo<=hi){
            int mid=lo+((hi-lo)/2);
            int cntSub=countSub(nums,mid);
            if(cntSub>k){
                lo=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
    cout<<ans<<endl;
    return 0;
}