#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
/*Approach- 
1. Xor all numbers and store result in ans the odd one out is the answer
*/
int singleNumber(vector<int>& nums) {
    int ans=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans^=nums[i];
    }
    return ans;
}
int main(){
  
    return 0;
}