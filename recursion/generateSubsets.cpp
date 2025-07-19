#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
/*Approach- 
1. Create a class named Solution.
2. Inside the class, declare a 2D vector `res` to store all the subsets.
3. Define a helper function `backtrack` which takes the following arguments:
   * current index `index`
   * reference to input array `nums`
   * reference to current subset vector `temp`
4. In the `backtrack` function, first push the current subset `temp` into the result vector `res`.
5. Start a for loop from `i = index` to the end of the `nums` array.
6. Inside the loop, push `nums[i]` into the current subset `temp`.
7. Recursively call the `backtrack` function with the next index `i + 1`.
8. After the recursive call, remove the last element from `temp` to backtrack.
9. Now define the main function `subsets` that takes the input array `nums`.
10. Inside the `subsets` function, create an empty vector `temp` to store the current subset.
11. Call the helper function `backtrack` with starting index 0, the `nums` array, and the empty `temp` vector.
12. Return the result vector `res` which contains all the subsets.

*/
void backtrack(int index, vector<int>& nums, vector<int>& temp,vector<vector<int>>& res) {
    res.push_back(temp);   // Add current subset to result

    for (int i = index; i < nums.size(); ++i) {
        temp.push_back(nums[i]);         // Include nums[i]
        backtrack(i + 1, nums, temp,res);    // Recurse with next index
        temp.pop_back();                 // Backtrack
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;   // To store all subsets
    vector<int> temp;    // Current subset being built
    backtrack(0, nums, temp,res);
    return res;
}




int main(){
  

    return 0;
}