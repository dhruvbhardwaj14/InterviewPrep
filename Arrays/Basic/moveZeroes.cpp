#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.*/
/*Approach- take a pointer zer that keeps track of zeroes and a pointer idx that keeps track of the all the terms now start from the start of the array and replace first zero which is before the idx with the idx(non zero) element and swap values and also take care of edge cases*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int zer=0;
    for (int idx = 0; idx < nums.size(); idx++)
    {
        while (nums[zer]!=0 && zer<nums.size())
        {
            zer++;
        }
        if(zer==nums.size()){
            break;
        }
        if(nums[idx]!=0){
            if(idx>zer){
                int temp=nums[idx];
                nums[idx]=0;
                nums[zer]=temp;
                zer++;
            }
        }
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
    return 0;
}
// 0 0 0 0 0 1 1 1 1
// 1 0 0 0 0 0 1 1 1