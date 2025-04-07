#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates.
*/
/*Approach- 
1. check if the arr[mid] is equal to target then return mid
2. if not then decide which portion of array is sorted either left half or right half 
and we only choose one of each 
if left half is sorted i.e. arr[mid]>arr[lo] and also arr[mid]>target>arr[lo] target is in range then move to left half but if target is not in that range then move to right half
els if right half is sorted and target in range then move to right half and if target not in range then move to left half
3. this may fail on this input [3,1,2,3,3,3,3] when arr[mid]==arr[lo]==arr[hi];
trim it down from both ends and you are done
*/
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int lo=0,hi=nums.size()-1;
    while(lo<=hi){
    int mid=lo+((hi-lo)/2);
    if(nums[mid]==target){
        cout<<true<<endl;
        return 0;
    }
    if(nums[mid]==nums[lo] && nums[mid]==nums[hi]){
        lo=lo+1;
        hi=hi-1;
    }
    else if(nums[mid]>=nums[lo]){
        if(target>=nums[lo] && target<=nums[mid]){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    else{
        if(target>=nums[mid] && target<=nums[hi]){
                lo=mid+1;
            }
        else{
            hi=mid-1;
        }
    }
    } 
    cout<<false<<endl;
    return 0;
}