#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.*/
/*Approach- 
take ans as INT_MAX and in the arr find left or right half which one is sorted?
if left half sorted then min is arr[lo] sort it in ans by min(ans,arr[lo]) similarly do for right half
and keep moving and repeating
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int lo=0,hi=nums.size()-1,ans=INT_MAX;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(nums[mid]>=nums[lo]){
            ans=min(ans,nums[lo]);
            lo=mid+1;
        }
        else {
            ans=min(ans,nums[mid]);
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}