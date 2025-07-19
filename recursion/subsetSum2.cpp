#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
/*Approach- */
void getSum(int idx,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
    ans.push_back(ds);
    for (int i = idx; i < nums.size(); i++)
    {
        if(i!=idx && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        getSum(i+1,nums,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        getSum(0,nums,ds,ans);
        return ans;
}
int main(){
  
    return 0;
}