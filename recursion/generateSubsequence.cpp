#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of integers nums, return all possible subsequences of the array.
A subsequence is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
The solution set must not contain duplicate subsequences.
*/
/*Approach- 
always have an index in such problems
first add that element to array list-> take
remove that element and pass on list-> not take 
*/
void generateSubsequence(int idx,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
    if(idx>=nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    generateSubsequence(idx+1,nums,ans,temp);
    temp.erase(remove(temp.begin(), temp.end(), nums[idx]), temp.end());
    generateSubsequence(idx+1,nums,ans,temp);
}
vector<vector<int>> allSubsequences(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> temp;
    generateSubsequence(0,nums,ans,temp);
    return ans;
    
}
int main() {
    int t;
    cin >> t; // Number of testcases
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            cin >> nums[i];

        vector<vector<int>> ans = allSubsequences(nums);
        cout << "Subsequences:\n";
        for (auto& seq : ans) {
            cout << "[";
            for (int i = 0; i < seq.size(); ++i) {
                cout << seq[i];
                if (i < seq.size() - 1) cout << ",";
            }
            cout << "]\n";
        }
        cout << "Total: " << ans.size() << " subsequences\n\n";
    }
    return 0;
}