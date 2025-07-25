#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.*/
/*Approach-
From total length of string if we subtract length of longest palindromic string then we will get the characters who's duplicate needed to be added to string to make it palindrome (i.e. the asked min no. of insertion)
*/
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
int minInsertions(string s) {
    string rev=s;
    reverse(rev.begin(),rev.end());
    int total_Length=s.length();
    int palindromic_Length=longestCommonSubsequence(s,rev);
    int insertions=total_Length-palindromic_Length;
    return insertions;
}
int main(){
  
    return 0;
}