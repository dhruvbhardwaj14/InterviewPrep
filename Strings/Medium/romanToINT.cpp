#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer*/
/*Approach- 
1. map all numbers to corresponding value
2. if next letter value is greater than current one's then subtract it from ans
3. else add it to ans
4. return ans
*/
int romanToInt(string s) {
    map<char,int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X'] =10;
    mp['L'] =50;
    mp['C'] =100;
    mp['D'] =500;
    mp['M']=1000;
    int ans=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(mp[s[i+1]]>mp[s[i]]){
            ans-=mp[s[i]];
        }
        else{
            ans+=mp[s[i]];
        }
    }
    return ans;
}
int main(){
    cout<<romanToInt("IX")<<endl;
    return 0;
}