#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/
/* Approach- 
1. The goal is to find all unique combinations of numbers that sum up to the given target. Each number can be used at most once in each combination.
2. Begin by sorting the `candidates` array so that duplicates are adjacent, which helps in skipping them later.
3. Create a helper recursive function `getSum` that:
   * Accepts current index `idx`, the `candidates` array, the remaining `target`, the current path `list`, and the final answer list `ans`.
4. Base case: If `target == 0`, a valid combination is found, so add the current `list` to `ans` and return.
5. Use a `for` loop from index `idx` to the end of the array to try out each element as a candidate.
6. Skip duplicates by checking `if(i > idx && candidates[i] == candidates[i-1]) continue`. This ensures only the first occurrence is picked in the current recursion level.
7. If the current number `candidates[i]` is greater than the remaining `target`, break the loop early since the array is sorted and further numbers will also be too large.
8. Otherwise, pick the current number by pushing it into `list`.
9. Make a recursive call to `getSum`, passing `i+1` as the new index (because we cannot reuse the same element), and subtract the picked number from the `target`.
10. After the recursive call returns, backtrack by popping the last number from `list` to explore other possibilities.
11. Finally, return the complete list `ans` that contains all unique combinations.

*/
void getSum(int idx,vector<int>& candidates, int target,vector<int>& list,vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(list);
        return;
    }
    for (int i = idx; i < candidates.size(); i++)
    {
        if(i>idx && candidates[i]==candidates[i-1]) continue;
        if(candidates[idx]>target) break;
        list.push_back(candidates[i]);
        getSum(i+1,candidates,target-candidates[i],list,ans);
        list.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> list;
    vector<vector<int>> ans;
    getSum(0,candidates,target,list,ans);
    return ans;
}
int main(){
  
    return 0;
}