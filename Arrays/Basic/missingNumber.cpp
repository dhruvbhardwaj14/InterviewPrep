#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?*/
/*Approach- sum of n natural numbers is n(n+1)/2 and array sum will be just missing number short of that expectedsum so just return the difference*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    long long int exp=((n)*(n+1))/2;
    long long int sum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum+=nums[i];
    }
    cout<<exp-sum<<endl;
    
    return 0;
}