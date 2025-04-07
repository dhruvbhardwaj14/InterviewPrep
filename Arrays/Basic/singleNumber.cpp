#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/
/*Approach- xor all elements and it will in end give that number as result*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int ans=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans^=nums[i];
    }
    cout<<ans<<endl;
    return 0;
}