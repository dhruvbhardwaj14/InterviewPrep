#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.
Constraints:
1 ≤ arr.size() ≤ 10^6
−10^3 ≤ arr[i] ≤ 10^3, for each valid i
*/
/*Approach- 
Make a hashmap that stores the prefix sum and now for each sum u encounter check if it is 0,
if 0 then maxlen is i+1, but it if it is not 0 then check map if previously we encountered same sum at some index and that map has nothing but all the sum of alements till that index and if that exists then that means from that index to current index the array will give sum 0 and then update maxlen with max of maxlen and i-mp[sum](index)
then if not exist same sum then push the sum with index (sum,index) format in map.
*/
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int maxLen=0;
    int sum=0;
    map<int,int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
        if(sum==0){
            maxLen=i+1;
        }
        else{
            if(mp.find(sum)!=mp.end()){
                maxLen=max(maxLen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
    }
    cout<<maxLen<<endl;
    
    return 0;
}