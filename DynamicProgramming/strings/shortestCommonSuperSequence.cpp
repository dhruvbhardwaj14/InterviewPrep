#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
*/
/*Approach- 
longest common subsequence taken once and then print rest of the words
*/
string findLCS(int n, int m,string &s1, string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
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
    int len=dp[n][m];
    string ans="";
    for (int i = 0; i < len; i++)
    {
        ans+="$";
    }
    int index=len-1;
    int i=n,j=m;
    while (i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){
            ans[index--]=s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;//move top
        }
        else j--;//move left
    }
    return ans;	
}
string shortestCommonSupersequence(string str1, string str2) {
    int n=str1.size();
    int m=str2.size();
    string lcs=findLCS(n,m,str1,str2);
    string ans="";
    int i = 0, j = 0;
    for (char c : lcs) {
        // Add characters from str1 before LCS character
        while (i < str1.size() && str1[i] != c) {
            ans += str1[i++];
        }
        // Add characters from str2 before LCS character
        while (j < str2.size() && str2[j] != c) {
            ans += str2[j++];
        }
        // Add the LCS character
        ans += c;
        i++;
        j++;
    }
    // Add remaining characters from both strings
    ans += str1.substr(i);
    ans += str2.substr(j);
    return ans;
}
int main(){
  
    return 0;
}