#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/

/*
Approach- create a map and check for consecutive and as soon as we get a break we store the maximum length somewhere.
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
        mp[nums[i]]++;
    }
    int mx=0;
    int count=1;
    for (auto it : mp)
    {
        if(mp.find(it.first+1)!=mp.end()){
            count++;
        }
        else{
            mx=max(mx,count);
            count=1;
        }
    }
    cout<<mx<<endl;
    
    return 0;
}