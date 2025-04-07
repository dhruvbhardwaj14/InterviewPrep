#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/
/*Approach- 
since product of two negative numbers can also be positive and greater hence we take 3 numbers prod1,prod2,ans
traverse the array and store the max(currentElement,max(prod1*currentElement,prod2*currentElement)) in prod1 and in prod2 store the min(currentElement,min(currentElement*prod1,currentElement*prod2))
return max(ans,prod1)
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    cout<<result<<endl;
    return 0;
}