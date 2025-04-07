#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Could you solve the problem in linear time and in O(1) space?*/
/*Approach- sort the array then the majority element will always be the element at n/2 position so return it*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    cout<<nums[n/2]<<endl;
    return 0;
}