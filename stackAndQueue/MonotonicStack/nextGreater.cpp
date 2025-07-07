#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Could you find an O(nums1.length + nums2.length) solution?
*/
/*
Approach- 
1. Traverse nums2 from right to left using a stack to find the next greater element for each number.
2. Use an unordered map to store the next greater element for each number in nums2.
3. For each number, pop elements from the stack until you find a greater one or the stack becomes empty.
4. If the stack is empty, store -1 in the map; otherwise, store the top of the stack as the next greater element.
5. Finally, for each number in nums1, fetch its next greater element from the map and store it in the result vector.
*/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> nge;
    stack<int> st;
    vector<int> ans;

    for (int i = nums2.size()-1; i>=0; i--)
    {
        while (!st.empty()&& st.top()<=nums2[i])
        {
            st.pop();
        }
        if(st.empty()){
            nge[nums2[i]]=-1;
        }
        else{
            nge[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(nge[nums1[i]]);
    }
    return ans;

}
int main(){
  
    return 0;
}