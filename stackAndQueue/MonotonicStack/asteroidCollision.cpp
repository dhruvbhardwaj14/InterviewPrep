#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.*/
/*Approach- 
1. If it is a positive element push it to stack.
2. if negative element then pop from stack all the elements that are lesser than it on top!
3. now check if stack is not empty and stack top is equal to our negative asteroid element then also pop once
4. if stack is empty or it's top is negative we pusht the negative element to it and that's done

*/
vector<int> asteroidCollision(vector<int>& asteroids) {
        // 10 2 -5 4 3 7 -6 2 1 -4
        int n=asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if(asteroids[i]<0){
                while (!st.empty()&&abs(asteroids[i])>st.top() && st.top()>0)
                {
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i])) st.pop();
                else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main(){
  
    return 0;
}