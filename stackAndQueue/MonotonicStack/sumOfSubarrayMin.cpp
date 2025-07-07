#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.*/
/*Approach- 
logic in code using contribution of each element
*/
int sumSubarrayMins(vector<int>& arr) {
        int md=1e9+7;
        int ans=0;
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
            ans=(ans+contribution)%md;
        }
     return ans;   
}
int main(){
    return 0;
}