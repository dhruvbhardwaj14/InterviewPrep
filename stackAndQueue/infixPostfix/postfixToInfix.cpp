#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.*/
/*Approach- 
1. take iterator and a stack
2. traverse the array and whenever u encounter a
-> operand= push to stack
-> operator= pop top two elements from stack and put the operator between them such that the first pop is on right of operator while second pop at left of it and push them back to stack as a single 
*/
string postToInfix(string exp) {
    int i=0;
    stack<string> st;
    while (i<exp.length())
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9')) {
            st.push(string(1,exp[i]));
        }
        else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string toPush="("+s2+string(1,exp[i])+s1+")";
            st.push(toPush);
        }
        i++;
    }
    return st.top();
}
int main(){
  
    return 0;
}