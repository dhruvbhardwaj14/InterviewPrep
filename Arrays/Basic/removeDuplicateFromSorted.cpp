#include "bits/stdc++.h"
using namespace std;
// Problem Statement
/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k*/

// Approach- start from 1st index and dup will iterate and find the unique element each time and replace it by idx+1 that means next element from that array
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    if(nums.size()<1){
        return 0;
    }
    int idx=0;
    int k=1;
    for (int dup = 1; dup < nums.size(); dup++)
    {
        if(nums[dup]!=nums[idx]){
            idx++;
            nums[idx]=nums[dup];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<"\n"<<k<<endl;
    return 0;
}
