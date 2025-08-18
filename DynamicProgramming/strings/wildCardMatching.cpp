#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).*/
/*Approach-
Here’s a **plain-text explanation** of how wildcard pattern matching works, followed by how it's implemented using **recursion**, **memoization**, and **tabulation**.

---

## 🎯 **Problem Statement**

You’re given:

* A string `s`
* A pattern `p` that may include:

  * `?` → matches **exactly one** character
  * `*` → matches **any number** (including zero) of characters

You need to determine if the pattern `p` matches the string `s` **entirely**.

---

## 🧠 **Recursive Approach (Without Memoization)**

The idea is to compare characters from the end of both strings (`s[i]` and `p[j]`) using recursion:

1. **Base Cases:**

   * If both `s` and `p` are empty → return `true`
   * If pattern is empty but string is not → return `false`
   * If string is empty but pattern is not:

     * Only return `true` if all remaining characters in `p` are `*`

2. **Choices:**

   * If `p[j] == s[i]` or `p[j] == '?'`, recurse on the previous characters: `i-1, j-1`
   * If `p[j] == '*'`, it can match:

     * Zero characters → move to `j-1` (pattern only)
     * One or more characters → move to `i-1` (string only)
     * So: `match(i-1, j)` OR `match(i, j-1)`
   * Otherwise → return `false`

🧨 **Drawback:** This leads to exponential time due to overlapping subproblems.

---

## 🧩 **Memoization (Top-Down DP)**

Same logic as recursion, but use a 2D array `dp[i][j]` to **store results of subproblems**, so they aren't recomputed.

Steps:

1. Initialize a 2D array `dp` of size `(s.length) x (p.length)` filled with -1 (unknown)
2. On each recursive call, check if `dp[i][j]` is already computed
3. Store and reuse the result

✅ **Benefit:** Reduces time complexity to O(n\*m), where n = length of `s`, m = length of `p`

---

## 📊 **Tabulation (Bottom-Up DP)**

Instead of recursion, fill a DP table iteratively:

1. Create a 2D boolean array `dp[n+1][m+1]` where `dp[i][j]` means:

   > Does `s[0...i-1]` match `p[0...j-1]`?

2. **Initialization:**

   * `dp[0][0] = true` → empty string matches empty pattern
   * Fill first row (`dp[0][j]`) → if all characters in pattern so far are `*`
   * First column (`dp[i][0]`) = false (non-empty string cannot match empty pattern)

3. **Filling Table:**

   * If characters match or `?`, copy from top-left `dp[i-1][j-1]`
   * If `*`, take `dp[i-1][j]` (match one char) or `dp[i][j-1]` (match zero chars)
   * Else, `dp[i][j] = false`

Final answer is `dp[n][m]`

---

## ✅ Summary Table

| Approach        | Time Complexity | Space Complexity | Notes                                   |
| --------------- | --------------- | ---------------- | --------------------------------------- |
| Recursion       | Exponential     | O(Stack Depth)   | Simple but inefficient                  |
| Memoization     | O(n \* m)       | O(n \* m)        | Avoids repeated subproblems             |
| Tabulation      | O(n \* m)       | O(n \* m)        | Iterative, more space-efficient         |
| Space-Optimized | O(n \* m)       | O(m)             | Can reduce space to 1D with some effort |
*/
// recursive
bool getMatch(string s,string p,int i,int j){
    if(i<0 && j<0) return true; //both gets exhausted
    if(j<0 && i>=0) return false;//p gets exhausted that means not matched 
    if(i<0 && j>=0){ //if s gets exhausted and p not exhausted that must mean all rest in p must be * now
        for (int k = 0; k <=j; k++)
        {
            if(p[k]!='*') return false;
        }
        return true;
    }; 
    if(s[i]==p[j] || p[j]=='?') return getMatch(s,p,i-1,j-1);
    if(p[j]=='*') return (getMatch(s,p,i-1,j)||getMatch(s,p,i,j-1));
    return false;
}
bool isMatch(string s, string p) {
     return getMatch(s,p,s.size(),p.size());   
}
// memoization

bool getMatch(string &s, string &p, int i, int j, vector<vector<int>> &dp){
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0){
        for(int k = 0; k <= j; k++){
            if(p[k] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == p[j] || p[j] == '?')
        return dp[i][j] = getMatch(s, p, i-1, j-1, dp);

    if(p[j] == '*')
        return dp[i][j] = getMatch(s, p, i-1, j, dp) || getMatch(s, p, i, j-1, dp);

    return dp[i][j] = false;
}

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return getMatch(s, p, n-1, m-1, dp);
}
// tabulation
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;

    for(int j = 1; j <= m; j++){
        if(p[j-1] == '*')
            dp[0][j] = dp[0][j-1];
    }

    for(int i = 1; i <= n; i++){
        dp[i][0] = false; // pattern is empty, string not empty
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(p[j-1] == s[i-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

int main(){

  
    return 0;
}