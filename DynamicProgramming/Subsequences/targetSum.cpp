#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/
/*Approach- 
similar to countPartitionwithdifference
since we have to basically divide array into 2 parts 
1. sum of positive (s1)
2. sum of other positive(s2)
3. s1-s2=target(d)


Sure, here is the full **approach in plain text** for the `findTargetSumWays` problem using a space-optimized bottom-up dynamic programming approach:

---

We are given an array of integers and a target sum. We need to find the number of ways to assign '+' or '-' signs to elements such that their sum equals the target.

This can be transformed into a subset sum problem. Let totalSum be the sum of all elements in the array. The key idea is to divide the array into two subsets such that:

sum(positive subset) - sum(negative subset) = target
This can be rearranged to:
sum(positive subset) = (target + totalSum) / 2

So we just need to count the number of subsets whose sum is (target + totalSum) / 2.

Before proceeding, we check two conditions:

1. target + totalSum must be even, otherwise it's impossible to partition
2. target + totalSum must be non-negative, otherwise target is not achievable

If either condition fails, return 0.

Next, we define a dp array where dp\[s] stores the number of subsets with sum s.

We initialize dp\[0] = 1, because there's exactly one way to get sum 0 — by choosing no elements.

We then iterate through the array from last index to first. For each element, we prepare a new dp array based on the current one. For each possible sum s, we compute:

* notTake: the number of ways to get sum s without using the current element
* take: the number of ways to get sum s by using the current element (only if arr\[i] <= s)

We update dp\[s] = take + notTake
After processing all elements, the answer will be dp\[target], which stores the number of ways to get the required sum.
This version uses only two 1D arrays of size target + 1 and avoids using large 2D arrays, so it works efficiently for large inputs.
*/
int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int tSum = 0;
    for (int i = 0; i < n; i++) {
        tSum += arr[i];
    }

    // Edge Case Check
    if ((tSum + d) < 0 || (tSum + d) % 2 != 0) return 0;

    int target = (tSum + d) / 2;

    vector<int> prev(target + 1, 0);
    prev[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        vector<int> cur(target + 1, 0);
        for (int s = 0; s <= target; s++) {
            int notTake = prev[s];
            int take = 0;
            if (arr[i] <= s) take = prev[s - arr[i]];
            cur[s] = take + notTake;
        }
        prev = cur;
    }

    return prev[target];
}

int findTargetSumWays(vector<int>& nums, int target) {
    return countPartitions(nums, target);
}

int main(){
  
    return 0;
}