#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.*/
/*Approach- 
Sure, here's the entire explanation in **plain text**, no formatting or highlights:

---

Problem Statement (Intuition):
DP Definition:
Let dp\[i]\[target] represent the minimum number of coins needed to make the target amount using coin types from index i to the end.

Step-by-step Approach:

1. Define the recursive function:
   int getCoins(vector<int>& coins, int target, int idx, vector\<vector<int>>& dp)
   coins is the list of denominations, target is the remaining amount, idx is the current index in the coin list, and dp is the 2D table for memoization.

2. Base case:
   If target == 0, return 0, since no coins are needed anymore.
   If idx >= coins.size(), return 1e9 to represent that it’s impossible to form the amount using available coins.

3. Memoization check:
   If the current subproblem is already solved (dp\[idx]\[target] != -1), return the stored result.

4. Case 1 - Not take the coin at index idx:
   Call getCoins on the next index, keeping target the same.

5. Case 2 - Take the coin at index idx:
   If the current coin value is less than or equal to the target, take the coin and reduce the target. Add 1 to the result to count the coin taken. Call getCoins again with the same index since coins are unlimited.

6. Return and store the minimum of taking or not taking the coin in dp\[idx]\[target].

7. In the main function coinChange:
   Initialize the dp table with size \[n]\[amount + 1] and fill it with -1.
   Call the recursive function starting from index 0 and the given amount.
   If the returned result is greater than or equal to 1e9, return -1 indicating no combination possible.
   Else return the result.

Time and Space Complexity:
Time complexity is O(n \* amount) because there are n \* amount unique states.
Space complexity is O(n \* amount) for the dp table and recursion stack.
*/
int getCoins(vector<int>& coins, int target, int idx, vector<vector<int>>& dp) {
    if (target == 0) return 0;
    if (idx >= coins.size()) return 1e9;
    if (dp[idx][target] != -1) return dp[idx][target];

    int notTake = getCoins(coins, target, idx + 1, dp);
    int take = 1e9;
    if (coins[idx] <= target)
        take = 1 + getCoins(coins, target - coins[idx], idx, dp);

    return dp[idx][target] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int res = getCoins(coins, amount, 0, dp);
    return res >= 1e9 ? -1 : res;
}
// tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

    // Base case: For all i, if amount is 0, we need 0 coins
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    // Fill the first row (only using the 0th coin type)
    for (int t = 0; t <= amount; t++) {
        if (t % coins[0] == 0) {
            dp[0][t] = t / coins[0];
        }
    }

    // Build the table
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= amount; t++) {
            int notTake = dp[i - 1][t];
            int take = 1e9;
            if (coins[i] <= t) {
                take = 1 + dp[i][t - coins[i]]; // same i because coins can be reused
            }
            dp[i][t] = min(take, notTake);
        }
    }

    int res = dp[n - 1][amount];
    return res >= 1e9 ? -1 : res;
}

int main(){
  
    return 0;
}