#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.
Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
/*Approach - traverse from the right and make the last element a[n-1] as max element and as soon as any element is greater than the mx variable then update mx and push that element to ans vector and when all done reverse the ans vector as we have to traverse from the start. 
 */
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int mx=arr[n-1];
    ans.push_back(arr[n-1]);
    for (int i = n-2; i>=0; i--)
    {
        if(arr[i]>=mx){
            mx=arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    for (auto t : ans)
    {
        cout<<t<<" ";
    }
    
    
    
    return 0;
}