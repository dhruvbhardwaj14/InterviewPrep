#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a string s, find the length of the longest substring without duplicate characters.
*/
/*Approach- 
1. Take a hashmap of 255 characters that checks if visited or not
2. take two pointers l and r
3. move ahead in string whenever u encounter a not visited before character and update maxlen
4. if u encounter visited character move l to it's position
*/
int lengthOfLongestSubstring(string s) {
    int n=s.length();
    vector<int> hash(256,-1);
    int l=0,r=0,maxlen=0;
    while (r<n)
    {
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        maxlen=max(maxlen,(r-l+1));
        hash[s[r]]=r;
        r++;
    }
    return maxlen;
}
int main(){
  
    return 0;
}