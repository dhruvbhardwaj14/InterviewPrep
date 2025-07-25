#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given two strings ‘s1’ and ‘s2’.
Return the longest common subsequence of these strings.
If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.*/
/*Approach- */
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
            i--;
        }
        else j--;
    }
    return ans;	
}
int main(){
  
    return 0;
}