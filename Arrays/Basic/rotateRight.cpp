#include "bits/stdc++.h"
using namespace std;
// Problem Statement
/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?*/

/* Approach -  reverse(0, last index) → whole array
reverse(0, k - 1) → before k
reverse(k, last index) → after k */
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+(k%nums.size()));
    reverse(nums.begin()+(k%nums.size()),nums.end());
    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}