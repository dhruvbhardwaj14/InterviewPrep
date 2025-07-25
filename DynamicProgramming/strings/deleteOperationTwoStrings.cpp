#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.*/
/*Approach- 
find longestCommonsubsequence length of both strings and then for each string the leftover words sum is what all steps are required.
*/
int largestCommonSubsequence(string s1,string s2){
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
    
}
int minDistance(string word1, string word2) {
    int commonLength=largestCommonSubsequence(word1,word2);
    return (word1.size()-commonLength+word2.size()-commonLength);
}
int main(){
  
    return 0;
}