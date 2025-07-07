#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/
/*Approach- 
Uses approach of largest rectangle in histogram
make a new 2d matrix prefix sum to convert all the 1 0 matrix as a histogram and pass it to max rectangle histogram problem
*/
//histogram area code
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
//  this question code
int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> prefixSum(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    prefixSum[i][j] = 0;
                else
                    prefixSum[i][j] = (i == 0 ? 1 : prefixSum[i - 1][j] + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            maxArea=max(maxArea,largestRectangleArea(prefixSum[i]));
        }
        return maxArea;    
}
int main(){
  
    return 0;
}