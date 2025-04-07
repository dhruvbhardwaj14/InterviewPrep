#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109
*/
/*Approach - (when inputs are always positive integers) make a window which determines a sum and if sum>k then reduce size of window and sum as well while if sum <k increase size and sum as well

(when inputs both positive and negative)
1.First, we will declare a map to store the prefix sums and the indices.
2.Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
3.For each index i, we will do the following:
3.1 We will add the current element i.e. a[i] to the prefix sum.
3.2 If the sum is equal to k, we should consider the length of the current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
3.3 We will calculate the prefix sum i.e. x-k, of the remaining subarray.
3.4 If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
3.5 If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible and so we will consider the earliest index where the sum x-k has occurred. [Detailed discussion in the edge case section]*/
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // Positive only
    // int sum=arr[0];
    // int ans=0;
    // int i=0;
    // int e=0;
    // while(e<arr.size())
    // {
    //     while(i<=e && sum>k)
    //     {
    //         sum-=arr[i];
    //         i++;
    //     }
    //     if(sum==k){
    //         ans=max((e-i+1),ans);
    //     }
    //     e++;
    //     if(e<arr.size()) sum+=arr[e];
    // }
    // cout<<ans<<endl;

    // Positive and negative both
    int n = arr.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += arr[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    cout<<maxLen<<endl;
    return 0;
}