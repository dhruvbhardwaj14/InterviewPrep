#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/
/*
Approach- 
Here’s the approach based on the given MinStack code:
* Maintain a single stack to store values, with some entries modified to encode the previous minimum.

* Track the current minimum in a separate variable `mn`.

* On push:
  * If the new value is ≥ mn, push it directly.
  * If it's < mn, push a modified value `2*val - mn` and update `mn` to `val`. 

* On pop:
  * If the top is < mn, it's a modified value, so decode the previous minimum as `2*mn - top`.

* On top:
  * If top ≥ mn, return it directly.
  * If top < mn, the actual top is `mn` (it's a modified value).

* On getMin, return `mn`.


🧠 Intuition behind using `2 * val - mn`:
The key idea is to encode the previous minimum into the value pushed onto the stack, so that we can recover it later during `pop()` without using extra space.

🔍 Why `2 * val - mn`?
Let’s assume:
* `val` is the new value being pushed (and it's less than current `mn`).
* We need to remember the old `mn` somehow, but we don’t want to store it in a second stack.
So instead of pushing `val`, we push `2 * val - mn`.
This value is always less than `val`, so we can detect it's a special (encoded) value when popping.

🔄 Recovery logic:
* On pop, if the popped value `x` is less than `mn`, then it's an encoded value.
* Use the formula:
  old mn=2×currentmn − x
  This reverses the encoding.

✅ Example:
1. Stack is empty, `mn = ∞`.
2. Push 5 → stack = \[5], `mn = 5`
3. Push 3 → since 3 < 5, push `2*3 - 5 = 1` → stack = \[5, 1], `mn = 3`
4. Pop → top is 1, which is less than current `mn = 3`, so:
    old mn=2×3−1=5
   → `mn` is restored to 5.

Summary:
Using `2*val - mn` lets you:
* Flag a modified value (since it's always < `val`)
* Encode previous `mn`
* Recover it later during `pop` — all in constant space and time.
*/
class MinStack {
    stack<long long> st;
    long long mn = INT_MAX;

public:
    MinStack() {
    }

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            mn = value;
            st.push(value);
        } else {
            if (value >= mn) {
                st.push(value);
            } else {
                st.push(2LL * value - mn);
                mn = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long top = st.top();
        st.pop();
        if (top < mn) {
            mn = 2LL * mn - top;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long top = st.top();
        if (top >= mn) return top;
        return mn;
    }

    int getMin() {
        return mn;
    }
};
int main(){
  
    return 0;
}