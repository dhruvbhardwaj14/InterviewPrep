#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.*/
/*Approach- run normal binary search*/
int main(){
    int target,n;
    cin>> n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int lo=0,hi=nums.size()-1;
    while (lo<=hi)
    {
        int mid=lo+((hi-lo)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) lo=mid+1;
        else hi=mid-1;
    }
    return 0;
}