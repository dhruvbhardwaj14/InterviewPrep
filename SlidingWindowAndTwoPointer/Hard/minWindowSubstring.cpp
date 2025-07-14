#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.*/
/*Approach- 
1. Count frequency of each character in `t` using a hash map.
2. Expand the window by moving `r` and include characters from `s`, reducing `cnt` when a required character is found.
3. When all characters from `t` are matched (`cnt == 0`), try shrinking the window from the left to find the minimum.
4. While shrinking, if a required character is removed, increase `cnt` and move `l` forward.
5. Keep track of the smallest valid window and return the substring once the traversal ends.

*/
string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int l=0,r=0,minlen=INT_MAX,sidx=-1,cnt=0;
        for (int i = 0; i < t.length(); i++)
        {
            hash[t[i]]++;
        }
        while (r<s.size())
        {
            if(hash[s[r]]>0) cnt=cnt+1;
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sidx=l;
                }
                hash[s[l]]--;
                if(hash[s[l]]>0) cnt=cnt-1;
                l++;
            }
            r++;
        }
        return (sidx==-1)?"":s.substr(sidx,minlen);
}
int main(){
  
    return 0;
}