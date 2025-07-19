#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
/*Approach- 
1. The problem is to find all unique combinations of candidates where the chosen numbers sum to the target. Each number in candidates may be used **unlimited times**.
2. The function `combinationSum` initializes:
   * an empty list `list` to store current combination,
   * a 2D list `ans` to store all valid combinations.
3. It calls the recursive helper function `getSum` starting from index `0`.
4. In `getSum`:
   * The base case checks if `idx` has reached the end of the `candidates` array.
     * If yes, and if `target == 0`, that means a valid combination is found, so it's added to `ans`.
     * If `target != 0`, it means the current path doesn't lead to a valid combination.
5. Otherwise, for each index:
   * First, check if the current candidate can be picked (i.e., `candidates[idx] <= target`).
     * If yes:
       * Add it to the `list`.
       * Call `getSum` recursively with:
         * the same index (`idx`) because we can pick the same number again.
         * reduced `target` (subtract current number).
       * After the recursive call, **backtrack** by removing the last added number from `list`.
6. Whether we pick the number or not, we always also try the path of **not picking** the current candidate:
   * Call `getSum` with `idx + 1` to move to the next number without picking current one.
7. Eventually, all valid combinations are collected in `ans` and returned by `combinationSum`.


*/
void getSum(vector<int>& candidates, int target,vector<int>& list,int idx,vector<vector<int>>& ans){
    if(idx==candidates.size()){
        if(target==0){
            ans.push_back(list);
        }
        return;
    }
    if(candidates[idx]<=target){
    list.push_back(candidates[idx]);
    getSum(candidates,target-candidates[idx],list,idx,ans);
    list.pop_back();
    }
    getSum(candidates,target,list,idx+1,ans);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> list;
        vector<vector<int>> ans;
        getSum(candidates,target,list,0,ans);
        return ans;
}
int main(){
  
    return 0;
}