#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. */
/*Approach- 

*/
void getSums(int idx,vector<int>& arr,vector<int>& ans,int sum){
    if(idx>=arr.size()){
        ans.push_back(sum);
        return;
    }
    sum+=arr[idx];
    getSums(idx+1,arr,ans,sum);
    sum-=arr[idx];
    getSums(idx+1,arr,ans,sum);
}
vector<int> subsetSums(vector<int>& arr) {
    vector<int> ans;
    int sum=0;
    getSums(0,arr,ans,0);
    return ans;
    
}
int main(){
  
    return 0;
}