#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.*/
/*Approach- lowerbound gives first occurence while upperbound-1 give last occurence*/
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    if(nums.size()==0) cout<<-1<<-1<<endl;
    vector<int> v = {-1,-1};
    int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
    if(lb>=0 && lb<nums.size() && nums[lb]==target){
        v[0]=lb;
    }
    if(ub<nums.size() && ub>=0 && nums[ub]==target){
        v[1]=ub;
    }
    cout<<v[0]<<v[1]<<endl;
    return 0;
}