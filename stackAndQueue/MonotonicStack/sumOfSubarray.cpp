#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.*/

/*
Approach- 
1. Find sumOfsubarray Minimum and maximum both and return their difference
*/
long long sumOfSubArrayMin(vector<int>& arr){
    // find nse and pse
    long long  ans=0;
    // next smaller element
    vector<int> nse(arr.size());
    stack<int> st;
    for (int i = arr.size()-1; i>=0; i--)
    {
        while (!st.empty()&& arr[i]<=arr[st.top()])
        {
            st.pop();
        }
        if(!st.empty()){
            nse[i]=st.top();
        }
        else{
            nse[i]=arr.size();
        }
        st.push(i);
    }
    // clean the stack
    while (!st.empty())
    {
        st.pop();
    }
    // previous smaller or equal element-> since for arr -> 1,1 it will take 1,1 subarray two times so for either of both pse or nse i have to find equal as well
    vector<int> pse(arr.size());
    for (int i = 0; i<arr.size(); i++)
    {
        while (!st.empty()&& arr[i]<arr[st.top()])// remove equal to
        {
            st.pop();
        }
        if(!st.empty()){
            pse[i]=st.top();
        }
        else{
            pse[i]=-1;
        }
        st.push(i);
    }
    // main logic 
    for (int i = 0; i < arr.size(); i++)
    {
        long long contribution=(i-pse[i])*(nse[i]-i)*1LL*arr[i];
        ans=(ans+contribution);
    }
    return ans;   
}
long long sumOfSubArrayMax(vector<int>& arr){
    // find nge and pge
    long long  ans=0;
    // next greater element
    vector<int> nge(arr.size());
    stack<int> st;
    for (int i = arr.size()-1; i>=0; i--)
    {
        while (!st.empty()&& arr[i]>=arr[st.top()])
        {
            st.pop();
        }
        if(!st.empty()){
            nge[i]=st.top();
        }
        else{
            nge[i]=arr.size();
        }
        st.push(i);
    }
    // clean the stack
    while (!st.empty())
    {
        st.pop();
    }
    // previous greater or equal element-> since for arr -> 1,1 it will take 1,1 subarray two times so for either of both pse or nse i have to find equal as well
    vector<int> pge(arr.size());
    for (int i = 0; i<arr.size(); i++)
    {
        while (!st.empty()&& arr[i]>arr[st.top()])// remove equal to
        {
            st.pop();
        }
        if(!st.empty()){
            pge[i]=st.top();
        }
        else{
            pge[i]=-1;
        }
        st.push(i);
    }
    // main logic 
    for (int i = 0; i < arr.size(); i++)
    {
        long long contribution=(i-pge[i])*(nge[i]-i)*1LL*arr[i];
        ans=(ans+contribution);
    }
    return ans;
}
long long subArrayRanges(vector<int>& nums) {
        return (sumOfSubArrayMax(nums)-sumOfSubArrayMin(nums));
}
int main(){
  
    return 0;
}