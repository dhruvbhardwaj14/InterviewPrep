#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/
/*Approach- simply implement lowerbound*/
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    cout<<(lower_bound(nums.begin(),nums.end(),target)-nums.begin())<<endl;
    return 0;
}