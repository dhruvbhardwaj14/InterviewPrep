#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/
/*Approach- 
area of rectangle by each heights[i] is 
heights[i]*(nse-pse-1);-> find max of it for all elements in heights[i]

*/
int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int> st;
    int maxArea=0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty()&&heights[st.top()]>heights[i])
        {
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=(st.empty())?-1:st.top();
            maxArea=max(maxArea,(heights[element]*(nse-pse-1)));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int nse=n;
        int element=st.top();
        st.pop();
        int pse=(st.empty())?-1:st.top();
        maxArea=max(maxArea,(heights[element]*(nse-pse-1)));
    }

    return maxArea;
}
int main(){
  
    return 0;
}