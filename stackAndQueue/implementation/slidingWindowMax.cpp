#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
*/
/*Approach- 
Traverse the array while maintaining a deque to store indices of useful elements.
Remove indices from the front if they are out of the current window (i - k).
Remove indices from the back if their corresponding values are smaller than the current element.
Add the current index to the deque.
Once the window is of size k or more, record the element at the front of the deque as the maximum.
Repeat until the end of the array and return the result.
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        
        if (!dq.empty()&&dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty()&& nums[dq.back()]<=nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main(){
  
    return 0;
}