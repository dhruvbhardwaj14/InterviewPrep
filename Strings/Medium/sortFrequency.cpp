#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/
/*Approach-
1. using map find frquencies - O(N)
2. for each frequency make a vector of vector of char where each index represent frequency and each vector in that index has a vector of char having that frequency - O(N)
3. using this bucket traverse reverse order and start putting in ans string the number of times that char appears max<s.length - O(N)
4. Space complexity - O(N)
5. Time complexity - O(N)

*/
string frequencySort(string s) {
    int n=s.length();
    map<char,int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    vector<vector<char>> bucket(n+1);
    string ans;
    for(auto it: mp){
        bucket[it.second].push_back(it.first);
    }
    for (int i = n; i>0; i--)
    {
        for(auto ch:bucket[i]){
            for(int j=0;j<i;j++){
                ans+=ch;
            }
        }
    }
    return ans;
}
int main(){
  
    return 0;
}