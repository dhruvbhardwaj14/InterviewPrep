#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. The array contains one or more peaks, return the index to  any of the peak.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.*/
/*Approach- 
since a peak element is like a mountain peak in which before there is a increasing curve and after it is a decreasing curve so check for mid if it's peak and if not check it's neighbours if mid greater than prev that mean it is in a increasing fashion curve that means peak is on right of it that means lo=mid+1 but if mid is greater than it's next element then that means it is a decreasing fashion curve and hence peak is on left half i.e. hi=mid-1;
*/
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        int lo=1,hi=nums.size()-2;
        while(lo<=hi){
            int mid=lo+((hi-lo)/2);
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                cout<<nums[mid]<<endl;
                return 0;
            }
            else if(nums[mid]>nums[mid-1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    return 0;
}