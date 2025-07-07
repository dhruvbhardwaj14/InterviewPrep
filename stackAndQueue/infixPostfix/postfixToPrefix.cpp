#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form*/
/*Approach- 
1. take iterator and a stack
2. traverse the expression and whenever u encounter a
-> operand= push to stack
-> operator= pop top two elements from stack and put the operator first then second pop and thne first pop and push them back to stack as a single 
*/
string postToPre(string post_exp) {
    int i=0;
    stack<string> st;
    while (i<post_exp.length())
    {
        if ((post_exp[i] >= 'A' && post_exp[i] <= 'Z') || (post_exp[i] >= 'a' && post_exp[i] <= 'z') || (post_exp[i] >= '0' && post_exp[i] <= '9')) {
            st.push(string(1,post_exp[i]));
        }
        else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string toPush=string(1,post_exp[i])+s2+s1;
            st.push(toPush);
        }
        i++;
    }
    return st.top();
}
int main(){
  
    return 0;
}