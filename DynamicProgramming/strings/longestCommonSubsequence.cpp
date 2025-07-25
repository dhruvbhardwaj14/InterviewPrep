#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.*/
/*Approach- 
if any of index is negative then length of lcs is 0
if both characters at any index matches then reduce both by 1.
if both characters at any index not match then run recursion on first idx1-1 and idx2 as it is and similarly for idx2-1 and idx1 as it is and find max of both.
*/
// recursive
int getMatch(string text1,string text2,int idx1,int idx2){
    if(idx1<0 || idx2<0) return 0;
    if(text1[idx1]==text2[idx2]){
        return 1+getMatch(text1,text2,idx1-1,idx2-1);
    }
    else{
        return max(getMatch(text1,text2,idx1-1,idx2),getMatch(text1,text2,idx1,idx2-1));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    return getMatch(text1,text2,text1.size()-1,text2.size()-1);
}
// memoization-> dp[i][j]=lenght of longest common subsequence from 0toi in string1 and 0toj in string2
int getMatch(string text1,string text2,int idx1,int idx2, vector<vector<int>>& dp){
    if(idx1<0 || idx2<0) return 0;
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(text1[idx1]==text2[idx2]){
        return dp[idx1][idx2]=1+getMatch(text1,text2,idx1-1,idx2-1,dp);
    }
    else{
        return dp[idx1][idx2]=max(getMatch(text1,text2,idx1-1,idx2,dp),getMatch(text1,text2,idx1,idx2-1,dp));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
    return getMatch(text1,text2,text1.size()-1,text2.size()-1,dp);
}
// tabulation
int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size();
    int m=text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m];
    
}
int main(){
  
    return 0;
}