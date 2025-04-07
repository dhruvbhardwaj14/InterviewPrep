#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. From the subarray arr[i...j], select the smallest and second smallest numbers and add them, you will get the score for that subarray. Return the maximum possible score across all the subarrays of array arr[].

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ arr.size ≤ 10^5
1 ≤ arr[i] ≤ 10^6
*/
/*
Approach- 
if two greatest elements are consecutive then only their sum will be maximum so we just have to find the sum of the consecutive elements of the array
*/
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    for (int i = 1; i < arr.size(); i++)
    {
        ans=max(arr[i-1]+arr[i],ans);
    }
    cout<<ans<<endl;
    
    return 0;
}
