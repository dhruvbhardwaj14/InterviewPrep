#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Expected Time Complexity: O(log(n))
Expected Auxiliary Space: O(1)
*/
/*Approach- 
1. find minimum in sorted array and it's index is the required answer
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int lo=0,hi=nums.size()-1,mn=INT_MAX,idx=0;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(nums[mid]>=nums[lo]){
            idx=(nums[lo]<mn)?lo:idx;
            mn=min(mn,nums[lo]);
            lo=mid+1;
        }
        else {
            idx=(nums[mid]<mn)?mid:idx;
            mn=min(mn,nums[mid]);
            hi=mid-1;
        }
    }
    cout<<idx<<endl;
    return 0;
}