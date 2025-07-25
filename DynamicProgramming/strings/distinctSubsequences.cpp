#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.*/
/*Approach- 
Concept of String Matching is here
Since count no. of ways we will write recurrence and find all possible ways
recursion
-> express in i and j
-> exportall possibilities
-> sum all possibiilitess and return
getDistinct(i,j)-> no. of distinct subsequences of t[0 to j] in s[0 to i]
We are counting **how many ways** we can transform string `s` into string `t` **by deleting characters only** (order matters).

1. **Recursive thinking**:
   * If `s[i] == t[j]`, we have two choices:
     * Match them → move both `i-1`, `j-1`
     * Skip `s[i]` → move only `i-1`
   * If they don't match, we can only skip `s[i]`.
2. **Memoization**:
   * Store overlapping subproblems in a `dp` table to avoid recomputation.
3. **Tabulation**:
   * Convert recursive relation into a bottom-up loop.
   * `dp[i][j]` represents: number of ways to form `t[0..j-1]` from `s[0..i-1]`.
4. **Initialization**:
   * Empty `t` can always be formed from any prefix of `s` → `dp[i][0] = 1`
   * Empty `s` cannot form non-empty `t` → `dp[0][j] = 0`
*/

// recursive
int getDistinct(string s,string t,int i,int j){
    if(i<0 && j<0){
        return 1;
    }
    if(i<0) return 0;
    if(j<0) return 1;
    if(s[i]==t[j]){
        return getDistinct(s,t,i-1,j-1)+getDistinct(s,t,i-1,j);
    }
    else{
        return getDistinct(s,t,i-1,j);
    }

}
int numDistinct(string s, string t) {
    int n=s.size(),m=t.size();
     return getDistinct(s,t,n,m);
}
// memoization
int getDistinct(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
    if (j < 0) return 1;        // target is fully matched
    if (i < 0) return 0;        // source exhausted before matching target
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j]) {
        // Option 1: Use the match (i-1, j-1), Option 2: Skip the character (i-1, j)
        return dp[i][j] = getDistinct(s, t, i - 1, j - 1, dp) + getDistinct(s, t, i - 1, j, dp);
    } else {
        // Only option: skip s[i]
        return dp[i][j] = getDistinct(s, t, i - 1, j, dp);
    }
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return getDistinct(s, t, n - 1, m - 1, dp);
}

// tabulation- Use unsigned long long or long long to avoid overflow in large inputs.
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

    // Base case: empty target string → exactly 1 way (by deleting all)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Fill the table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){
  
    return 0;
}