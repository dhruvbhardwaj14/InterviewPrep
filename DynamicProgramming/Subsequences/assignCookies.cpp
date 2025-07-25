#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.*/

/* Approach- 
sort the cookies and match each of them with the child's greed and using two pointers go ahead
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int idx1=0,idx2=0,cnt=0;
    while (idx1<g.size() && idx2<s.size())
    {
        if(s[idx2]>=g[idx1]){
            idx2++;
            idx1++;
            cnt++;
        }
        else{
            idx2++;
        }
    }
    return cnt;
}
int main(){
  
    return 0;
}