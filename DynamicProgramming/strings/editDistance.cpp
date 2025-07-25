#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character*/
/*Approach- 
Great! You're solving the classic **Edit Distance (Levenshtein Distance)** problem.

Let's go step-by-step:

---

## 🧠 Problem:

You are given two strings `word1` and `word2`.
You need to find the **minimum number of operations** (insert, delete, replace) to convert `word1` into `word2`.

---

## ✅ Your Recursive Approach (Top-down without memoization)

Your recursive logic is mostly correct, except:

```cpp
return getDistance(word1, word2, word1.size(), word2.size());
```

should be:

```cpp
return getDistance(word1, word2, word1.size() - 1, word2.size() - 1);
```

since you're using **0-based indexing**.

---

## ✅ 1. Memoized Version (Top-Down DP)

### 🔧 Code:

```cpp
int getDistance(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        return dp[i][j] = getDistance(s, t, i - 1, j - 1, dp);
    } else {
        int insert = 1 + getDistance(s, t, i, j - 1, dp);
        int del = 1 + getDistance(s, t, i - 1, j, dp);
        int replace = 1 + getDistance(s, t, i - 1, j - 1, dp);
        return dp[i][j] = min({insert, del, replace});
    }
}

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return getDistance(word1, word2, n - 1, m - 1, dp);
}
```

---

## ✅ 2. Tabulation Version (Bottom-Up DP)

We build a DP table iteratively.

### 🔧 Code:

```cpp
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases:
    for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete all
    for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert all

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no op
            } else {
                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insert, del, replace});
            }
        }
    }

    return dp[n][m];
}
```

---

## 🧠 Plain English Explanation of the Approach

You're converting `word1` to `word2` using the **minimum number of operations**.

The allowed operations:

* **Insert** a character
* **Delete** a character
* **Replace** a character

### 1. **Recursive Thinking**:

* Compare the last characters of the strings:

  * If they are equal → No operation, move to previous characters.
  * If not equal → Try all 3 operations and take the minimum.

### 2. **Memoization**:

* Save intermediate results in a `dp[i][j]` table so that you don’t solve the same subproblem multiple times.

### 3. **Tabulation**:

* Start from the smallest subproblems (empty strings) and iteratively fill the `dp` table.
* `dp[i][j]` means: **min operations to convert first `i` characters of `word1` to first `j` characters of `word2`.**

### 4. **Base Cases**:

* If one string is empty:

  * Convert `"abc"` to `""` → 3 deletions.
  * Convert `""` to `"xyz"` → 3 insertions.
*/
// recursive getDistance(i,j) signifies min opn to convert string s[0..i] into t[0..j]
int getDistance(string s,string t,int i,int j){
    if(i<0) return j+1;//if s is exhausted then leftover letters in t is the number of characters we need to insert to s to get t so min opn are equal to j+1;
    if(j<0) return i+1;//if t get exhausted that means we need i+1 delete operations to make s and t equal
    if(s[i]==t[j]){
        return getDistance(s,t,i-1,j-1);
    }
    else{
        // insert operation 1 step Hypothetically insert that character to end but i remains at same position and j goes back since it matched with hypothetically made character
        int insert=1 + getDistance(s,t,i,j-1);
        // delete operation 1 step delete that character and move back in s and j in t remains at same since not matched
        int del = 1 + getDistance(s,t,i-1,j);
        // replace opeartion replace that character and now it's matched so both strings go back
        int replace= 1+ getDistance(s,t,i-1,j-1);
        return min({insert,del,replace});
    }
}
int minDistance(string word1, string word2) {
    return getDistance(word1,word2,word1.size(),word2.size());
}
// memoization
int getDistance(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        return dp[i][j] = getDistance(s, t, i - 1, j - 1, dp);
    } else {
        int insert = 1 + getDistance(s, t, i, j - 1, dp);
        int del = 1 + getDistance(s, t, i - 1, j, dp);
        int replace = 1 + getDistance(s, t, i - 1, j - 1, dp);
        return dp[i][j] = min({insert, del, replace});
    }
}

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return getDistance(word1, word2, n - 1, m - 1, dp);
}
// tabulation
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases:
    for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete all
    for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert all

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no op
            } else {
                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insert, del, replace});
            }
        }
    }

    return dp[n][m];
}

int main(){
  
    return 0;
}