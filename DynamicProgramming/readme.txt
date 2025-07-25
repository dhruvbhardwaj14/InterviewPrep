2 ways
1. Tabulation ways-> bottom up
2. Memoization ways-> top down


Trick for writing any recursions
1. Try to represent the problem in terms of index
2. Do all possible stuff on that index according to problem statement
3. if problem says :-
        1. Count all ways-> summ all possible stuffs
        2. Min all ways-> min of all possible stuffs

How to convert Memoization to Tabulation
1. Define the DP array
2. Write the base case of memoization to tabulation format
3. Run for loop from a to x where a is the last idx the recursion calls for and x is the first idx recursion started with in top down approach (example a=1,x=n-1)
4. Replace statements of recursion with function replaced by mere dp array.
5. return dp[x]

in subsequence problems there is 2d Dp we have used
to find out what all things u need in a dp table 
look for what all things change in our recursion


For 2D DP tables memoization to tabulation 
Absolutely, Dhruv! Here's a **step-by-step plain text guide** to convert any **memoization-based DP** to **tabulation (bottom-up)**, written clearly so you can refer to it anytime.

---

## 🧾 Steps to Convert Memoization to Tabulation

### **Step 1: Identify DP State**

* Figure out what each `dp[...]` represents.
* Example: `dp[idx][target]` = number of subsets from index `idx` to end that sum to `target`.

---

### **Step 2: Determine the Parameter Ranges**

* Check the ranges of all variables in recursion.
* For example:

  * `idx` → `0 to n`
  * `target` → `0 to target`

---

### **Step 3: Create the DP Table**

* Create a 2D DP table based on the parameter ranges.
* Example:

  ```cpp
  vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
  ```

---

### **Step 4: Handle Base Case Initialization**

* Look at the base case in recursion:

  ```cpp
  if (idx == n) return (target == 0) ? 1 : 0;
  ```
* In tabulation:

  ```cpp
  dp[n][0] = 1;
  ```

---

### **Step 5: Write Nested Loops in Reverse Order**

* In recursion: `idx` increases (`idx + 1`) → In tabulation: `idx` decreases (loop from `n-1` to `0`)
* For each state, loop over the second parameter (`target`) in valid order:

  ```cpp
  for (int idx = n-1; idx >= 0; idx--) {
      for (int t = 0; t <= target; t++) {
          ...
      }
  }
  ```

---

### **Step 6: Translate Recurrence to Iterative Transition**

* Recursion:

  ```cpp
  dp[idx][target] = take + notTake;
  ```
* Iteration:

  ```cpp
  int take = 0;
  if (arr[idx] <= t)
      take = dp[idx+1][t - arr[idx]];

  int notTake = dp[idx+1][t];
  dp[idx][t] = take + notTake;
  ```

---

### **Step 7: Return Final Answer**

* In memoization: `return dp[0][target]` was result of initial call
* So in tabulation: return `dp[0][target]`

---

## ✅ Summary Template:

```
1. Understand what dp[i][j] represents.
2. Identify the range of i and j.
3. Initialize dp table with correct size and default values.
4. Set up base case based on the recursive base case.
5. Loop in reverse of the recursion order.
6. Fill dp[i][j] using recurrence relation.
7. Return dp[START_INDEX][START_TARGET] as the final answer.
```

-> template
// 1. Create DP table according to parameter ranges
vector<vector<type>> dp(PARAM1_RANGE, vector<type>(PARAM2_RANGE, INITIAL));

// 2. Initialize base cases according to the recursive base case
dp[...][...] = BASE_VALUE;

// 3. Loop over the parameters in reverse of recursion order
for (int i = RANGE1_REVERSE) {
    for (int j = RANGE2_NORMAL) {
        // 4. Recreate recursion transitions
        type take = 0;
        if (CONDITION) take = dp[NEXT_I][NEXT_J];

        type notTake = dp[NEXT_I][j];
        dp[i][j] = take + notTake;  // or max(), or min(), based on problem
    }
}

// 5. Return dp[STARTING_POINT]
return dp[START_IDX][START_TARGET];







---

## 🧭 Goal: Steps to Tabulate a Memoized DP on Strings

### 🔹 **Step 1: Understand the Parameters**

* Recursive call is `f(i, j)` where `i` and `j` are **indices into strings** `s1` and `s2`.

---

### 🔹 **Step 2: Define the DP Table**

* If recursive `f(i, j)` uses `i` and `j` as 0-based indices, your table will be size `(n+1) x (m+1)`.

```cpp
int n = s1.size(), m = s2.size();
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
```

Why `n+1`? Because we want:

* `dp[0][*]` to represent empty prefix of `s1`
* `dp[*][0]` to represent empty prefix of `s2`

---

### 🔹 **Step 3: Set Base Cases**

* Usually, all `dp[0][*] = 0` and `dp[*][0] = 0`
* Already handled by vector default initialization.

---

### 🔹 **Step 4: Convert Recursion to Loops**

* Loop over `i = 1 to n`
* Loop over `j = 1 to m`
* Replace `s1[i]` with `s1[i-1]` because `dp[i][j]` represents `s1[0...i-1]` and `s2[0...j-1]`.

---

### 🔹 **Step 5: Translate the Recurrence**

From:

```cpp
if (s1[i] == s2[j])
    return 1 + f(i-1, j-1);
else
    return max(f(i-1, j), f(i, j-1));
```

To:

```cpp
if (s1[i - 1] == s2[j - 1])
    dp[i][j] = 1 + dp[i - 1][j - 1];
else
    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
```

---

### 🔹 **Step 6: Return the Final Answer**

```cpp
return dp[n][m];
```

---

## 🧑‍💻 Full Example: LCS (Bottom-Up)

```cpp
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}
```

---

## 🧠 Quick Summary of Steps

| Step | What You Do                            |
| ---- | -------------------------------------- |
| 1    | Understand recursive parameters        |
| 2    | Create `dp[n+1][m+1]` table            |
| 3    | Initialize base cases (`dp[0][*] = 0`) |
| 4    | Convert recursion into nested loops    |
| 5    | Translate recursive relation to table  |
| 6    | Return `dp[n][m]`                      |

---

Would you like to see the **tabulation for Edit Distance** or **printing the actual LCS** as well?
