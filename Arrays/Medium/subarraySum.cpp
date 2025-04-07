#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/
/*Approach- 
First, we will declare a map to store the prefix sums and their counts.
Then, we will set the value of 0 as 1 on the map.
Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:
We will add the current element i.e. arr[i] to the prefix sum.
We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
Then we will store the current prefix sum in the map increasing its occurrence by 1. 
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int k;
    cin>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    map<int,int> mp;
    mp[0]=1;
    int sum=0;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        sum+=nums[i];
        mp[sum]++;
        ans+=mp[sum-k];
    }
    cout<<ans<<endl;
    return 0;
}