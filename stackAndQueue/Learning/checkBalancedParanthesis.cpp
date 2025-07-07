#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/
/*Approach- 
1. Initialize an empty stack.
2. Traverse the string `s` character by character.
3. For each character:
   * **If it's an opening bracket** (`(`, `{`, `[`):
     * Push it onto the stack.
   * **If it's a closing bracket** (`)`, `}`, `]`):
     1. Check if the stack is **not empty**.
     2. Check if the **top of the stack matches** the corresponding opening bracket:
        * If yes, **pop** the top element from the stack.
        * If no (mismatch) or the stack is empty, **return `false`** immediately.
4. After the entire string is processed:
   * If the stack is **empty**, return `true` (all brackets matched).
   * If the stack is **not empty**, return `false` (some brackets were not closed).
*/
bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty(); // If stack is empty at the end, it's valid
}
int main(){
  
    return 0;
}