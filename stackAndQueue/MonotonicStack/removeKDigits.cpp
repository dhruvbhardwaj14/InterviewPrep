#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/
/*Approach- 
1. Use a stack to keep digits in increasing order.
   * Traverse each digit of `num` from left to right.
   * For each digit, while the top of the stack is greater than the current digit and you still have digits to remove (`k > 0`), pop from the stack.
   * This ensures that you remove larger digits earlier, helping to form a smaller number.
2. Push the current digit to the stack.
3. If `k > 0` after the loop, pop the remaining digits from the top of the stack until `k == 0`.
4. Build the result string by popping all characters from the stack and reversing the result.
5. Remove leading zeros from the result string.
6. If the result is empty after removing zeros, return "0".
Intuition:
The goal is to always remove the highest possible digits from left to right to make the resulting number as small as possible. This is done greedily using a stack.
*/
string removeKdigits(string num, int k) {
    int n=num.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && k>0 && ((st.top()-'0')>(num[i]-'0')))
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k>0)
    {
        st.pop();
        k--;
    }
    if(st.empty()){
        return "0";    
    }
    string res="";
    while (!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    while (!res.empty() && res[0] == '0') {
        res.erase(0, 1);
    }
    
    return (res.empty())?"0":res;
    
}
int main(){
  
    return 0;
}