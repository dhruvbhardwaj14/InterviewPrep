#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
/*Approach- 
let's say we have n index in array then convert these all index from 0 to n-1 in a way that it forms n bit number starting from  0 to 2^n-1
let say we have 3 length array so n=3 therefore
indices-> 0 1 2
          0 0 0 -> 0
          0 0 1 -> 1
          0 1 0 -> 2
          0 1 1 -> 3
          1 0 0 -> 4
          1 0 1 -> 5
          1 1 0 -> 6
          1 1 1 -> 7 (2^(3)-1)
now move in this array and for each index if it's corresponing bit is set then take it else leave it
and push this vector in final vector later
*/
bool checkithSet(int x,int i){
    // return ((x)&(1<<i));//left shift
    return (x>>i)&1;
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    int subsets=1<<n;
    vector<vector<int>> ans;
    for (int i = 0; i < subsets-1; i++)
    {
        vector<int> list;
        for(int j=0;j<n;j++){
            if(checkithSet(i,j)){
                list.push_back(nums[j]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}
int main(){
  
    return 0;
}