#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.*/
/*Approach- 
1. take iterator and a stack
2. traverse the string in reverse and whenever u encounter a
-> operand= push to stack
-> operator= pop top two elements from stack and put the operator between them such that the second pop is on right of operator while first pop at left of it and push them back to stack as a single 
*/
string preToInfix(string pre_exp) {
    int i=pre_exp.length();
    stack<string> st;
    while (i>=0)
    {
        if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {
            st.push(string(1,pre_exp[i]));
        }
        else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string toPush="("+s1+string(1,pre_exp[i])+s2+")";
            st.push(toPush);
        }
        i--;
    }
    return st.top();
}
int main(){
  
    return 0;
}