#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/
/*Approach- 
make a lastseen array and whenever we encounter all three of a,b,c we add to count the lower index of the window a,b,c+1 making the number of subarrays
*/
int numberOfSubstrings(string s) {
    int lastSeen[3]={-1,-1,-1};
    int cnt=0;
    for (int i = 0; i < s.size(); i++)
    {
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1&&lastSeen[1]!=-1&&lastSeen[2]!=-1){
            cnt+=1+min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
    }
    return cnt;
}
int main(){
  
    return 0;
}