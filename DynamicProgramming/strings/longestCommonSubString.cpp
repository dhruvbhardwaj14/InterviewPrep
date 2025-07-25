#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.*/
/*Approach- 
since it's consecutive so we do not need to break for both indices idx-1,idx2 and idx1,idx2-1
in that case we simply write 0
the answer is the maximum ans located in DP array
*/
int longestCommonSubstr(string& s1, string& s2) {
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    int ans=INT_MIN;
    for (auto it : dp)
    {
        for (auto i : it)
        {
            ans=max(ans,i);
        }
        
    }
    return ans;
    
}
int main(){
  
    return 0;
}