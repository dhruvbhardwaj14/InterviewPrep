#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.*/
/*Approach- 
1. take iterator and a stack
2. traverse the  reverse expression and whenever u encounter a
-> operand= push to stack
-> operator= pop top two elements from stack and put first pop and then second pop and the operator last push them back to stack as a single 
*/
string preToPost(string pre_exp) {
    int i=pre_exp.length()-1;
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
            string toPush=s1+s2+string(1,pre_exp[i]);
            st.push(toPush);
        }
        i--;
    }
    return st.top();
}
int main(){
  
    return 0;
}