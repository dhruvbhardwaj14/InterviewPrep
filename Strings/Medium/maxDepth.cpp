#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.*/
/*Approach- 
for each )- increase count 
for each (- decrease count
parse the string and store max count at each step
*/
int maxDepth(string s) {
    int cnt=0;
    int ans=INT_MIN;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') cnt++;
        else if (s[i]==')') cnt--;
        ans=max(ans,cnt);
    }
    return ans;
}
int main(){
  
    return 0;
}