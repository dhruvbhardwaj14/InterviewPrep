#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Could you solve the problem in linear time and in O(1) space?
*/
/*
Approach- 
we know only 2 maximum elements can exist as such.
so take 4 variable el1,el2,cnt1,cnt2 and whenever traversing given array change according to the given below conditions
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    vector<int> ans;
    int cnt1=0,cnt2=0,el1=INT_MAX,el2=INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1=1;
        }
        else if(cnt2==0 && nums[i]!=el1){
                el2=nums[i];
                cnt2=1;
        }
        else if(nums[i]==el1) cnt1++;
        else if(nums[i]==el2) cnt2++;
        else {cnt1--;cnt2--;}
    }
    cnt1=0;
    cnt2=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==el1) cnt1++;
        if(nums[i]==el2) cnt2++;
    }
    int mini=floor(n/3);
    if(cnt1>mini) ans.push_back(el1);
    if(cnt2>mini) ans.push_back(el2);
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}