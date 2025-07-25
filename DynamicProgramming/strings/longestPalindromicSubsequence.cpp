#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.*/
/*Approach- 
tabulation
Let dp[i][j] be the length of the longest palindromic subsequence in the substring s[i..j].
If i == j, then it's a single character → length = 1.
Fill the table bottom-up, starting with substrings of length 1, then 2, ... up to n.
*/
// recursive
int getPalindrome(string s,int st,int e){
    if(st>e){
        return 0;
    }
    if(st==e) return 1;
    if(s[st]==s[e]){
        return 2+getPalindrome(s,st+1,e-1);
    }
    else{
        return max(getPalindrome(s,st+1,e),getPalindrome(s,st,e-1));
    }
}
int longestPalindromeSubseq(string s) {
    int st=0;
    int e=s.length()-1;
    return getPalindrome(s,st,e);
}
// memoization
int getPalindrome(string s,int st,int e,vector<vector<int>>& dp){
    if(st>e){
        return 0;
    }
    if(dp[st][e]!=-1) return dp[st][e];
    if(st==e) return 1;
    if(s[st]==s[e]){
        return dp[st][e]=2+getPalindrome(s,st+1,e-1,dp);
    }
    else{
        return dp[st][e]=max(getPalindrome(s,st+1,e,dp),getPalindrome(s,st,e-1,dp));
    }
}
int longestPalindromeSubseq(string s) {
    int n=s.size();
    int st=0;
    int e=s.length()-1;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return getPalindrome(s,st,e,dp);
}
// tabulation
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Step 1: All substrings of length 1 are palindromes of length 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Step 2: Check all substrings of length 2 to n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) {
                    dp[i][j] = 2; // two same letters
                } else {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // The result for the entire string is in dp[0][n-1]
    return dp[0][n - 1];
}



// another approach
// find lcs of s and reverse(s);
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
int longestPalindromeSubseq(string s) {
    string rev=s;
    reverse(rev.begin(),rev.end());
    return longestCommonSubsequence(s,rev);
}
int main(){
  
    return 0;
}