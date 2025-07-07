#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.
Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.
*/
/*
Approach- 
1.Take iterator, stack and ans(string)
2. if s[i] is an operand do nothing just add it to ans
3. if s[i] is an operator look into stack 
-> if stack top is lesser priority than push the operand to stack
-> else while stack top has more priority than current operator just pop the top and push to ans
and then push the operator to stacks
-> if u encounter ) pop top and add to ans every operator 
*/
int priority(char a){
    if(a=='^') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    return -1;
}
string infixToPostfix(string& s) {
    int i=0;
    string ans="";
    stack<char> st;
    while (i<s.length())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans=ans+s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else{
            while (!st.empty() && priority(s[i])<=priority(st.top()))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans=ans+st.top();
        st.pop();
    }
    return ans;
}
int main(){
  
    return 0;
}