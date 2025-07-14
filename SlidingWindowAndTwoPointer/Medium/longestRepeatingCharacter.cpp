#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.*/
/*Approach-
Use the logic to check if current len(r-l+1)<=k then update maxlen

*/
int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxfreq=0;
        vector<int> hash(26,0);
        while (r<s.size())
        {
           hash [s[r]-'A']++;
           maxfreq=max(maxfreq,hash[s[r]-'A']);
           if ((r-l+1)-maxfreq>k)
           {
            hash[s[l]-'A']--;
            maxfreq=0;
            l++;
           }
           if((r-l+1)-maxfreq<=k){
            maxlen=max(maxlen,r-l+1);
           }
           r++;
        }
        return maxlen;
}
int main(){
  
    return 0;
}