#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
*/
/*
Approach- 
1. **Define a helper function `isPalindrome(s, start, end)`**
   * It checks if the substring from `start` to `end` in string `s` is a palindrome.
   * Use a loop: while `start <= end`, check if `s[start] != s[end]`.
   * If not equal, return `false`; otherwise increment `start` and decrement `end`.
   * If loop completes, return `true` (it’s a palindrome).
2. **Define a recursive function `getPalindrome(idx, s, ans, ds)`**
   * `idx` is the current index in the string `s`.
   * `ans` is the final list of list of palindromic partitions.
   * `ds` is the current path (list of palindromic substrings so far).
3. **Base case of recursion**:
   * If `idx == s.length()`, it means you have partitioned the whole string.
   * Push `ds` (current partition path) into `ans` and return.
4. **Recursive case (loop from current index to end)**:
   * For every index `i` from `idx` to `s.length() - 1`:
     * Check if the substring `s[idx..i]` is a palindrome using `isPalindrome`.
     * If it is:
       * Push the substring `s.substr(idx, i - idx + 1)` to `ds`.
       * Call `getPalindrome(i + 1, s, ans, ds)` for the next part.
       * After recursion, backtrack by removing the last pushed substring (pop from `ds`).
5. **Define the main function `partition(s)`**
   * Create `ans` to store final result.
   * Create `ds` as temporary list to hold one partition path.
   * Call `getPalindrome(0, s, ans, ds)` to start recursion from index 0.
   * Return `ans`.
*/
bool isPalindrome(string s,int start,int end){
    while (start<=end)
    {
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}
void getPalindrome(int idx, string s,vector<vector<string>>& ans,vector<string>& ds){
    if(idx==s.length()){
        ans.push_back(ds);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if(isPalindrome(s,idx,i)){
            ds.push_back(s.substr(idx,i-idx+1));
            getPalindrome(i+1,s,ans,ds);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        getPalindrome(0,s,ans,ds);
        return ans;
}
int main(){
    
    return 0;
}