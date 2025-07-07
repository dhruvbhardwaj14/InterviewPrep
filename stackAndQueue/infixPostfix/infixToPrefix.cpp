#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Convert infix to prefix*/
/*
Approach- 
1.Reverse the string given
2. After reversing switch the ')' to '('
3. convert infix to postfix but under some controlled conditions
-> if priority of the given operator is equal to the current then also we popped in that but here it should be exactly smalelr
*/
int priority(char a){
    if(a=='^') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    return -1;
}
string infixToPrefix(string& s) {
    reverse(s.begin(),s.end()); 
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]==')') s[i]='(';
        else if(s[i]=='(') s[i]=')';
    }   
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
            if(s[i]=='^'){
                while (!st.empty() && priority(s[i])<=priority(st.top()))//priority exactly smaller not equal to
                {
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while (!st.empty() && priority(s[i])<priority(st.top()))//priority exactly smaller not equal to
                {
                    ans+=st.top();
                    st.pop();
                }
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
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string infix;
    cin >> infix;
    string prefix=infixToPrefix(infix);
    cout<<prefix<<endl;
    return 0;
}