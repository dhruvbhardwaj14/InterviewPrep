#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a string s, return the longest palindromic substring in s.s*/
/*Approach- 
1. We try every index i in the string as a potential center.
2. For each i, we do two types of expansions:
3. One assuming a single center (odd length): e.g. "aba"
4. One assuming two characters at center (even length): e.g. "abba"
5. In each expansion, we move left and right as long as characters match.
6. Track the longest palindrome found during all these expansions.
*/
string longestPalindrome(string s) {
    int start = 0, maxLen = 0;

    // Helper lambda function to expand around center
    auto expandFromCenter = [&](int left, int right) {
        // Expand while within bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // After loop ends, the actual palindrome is from left+1 to right-1
        int length = right - left - 1;
        if (length > maxLen) {
            maxLen = length;
            start = left + 1;
        }
    };

    // Try each index as a center
    for (int i = 0; i < s.length(); i++) {
        expandFromCenter(i, i);       // odd-length palindrome
        expandFromCenter(i, i + 1);   // even-length palindrome
    }

    return s.substr(start, maxLen);
}
int main(){
  
    return 0;
}