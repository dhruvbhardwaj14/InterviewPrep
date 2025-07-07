#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/
/*Approach- 
1. Since it's similar to nge all is same but consider whenever ROTATED IS GIVEN U HUPOTHETICALLY ASSUME A 2N size same array with elements repeated after first N elements
*/
vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> nge;
    stack<int> st;
    int n=nums.size();
    for (int i = (2*n)-1; i>0; i--)
    {
        while (!st.empty()&&nums[i%n]>=st.top())
        {
            st.pop();
        }
        if(i<n){
            nge[i]=(st.empty())?-1:st.top();
        }
        st.push(nums[i%n]);
    }
    return nge;
}
int main(){
  
    return 0;
}