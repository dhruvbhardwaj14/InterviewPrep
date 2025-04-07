#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
/*Approach- 
take two pointers which start from the end of the first array and start of second array and whenever the element at left is greater than right element then swap them else break and after all this sort both arrays and then merge into array 1 
*/
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> nums1(m+n);
    vector<int> nums2(n);
    for (int i = 0; i < m; i++)
    {
        cin>>nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>nums2[i];
    }
    int left=m-1;
    int right=0;
    while (left>=0 && right<n)
    {
        if(nums1[left]>nums2[right]){
            swap(nums1[left],nums2[right]);
            right++;
            left--;
        }
        else{
            break;
        }
    }
    sort(nums1.begin(),nums1.begin()+m);
    sort(nums2.begin(),nums2.end());
    int t=0;
    for (int i = m; i < nums1.size(); i++)
    {
        nums1[i]=nums2[t++];
    }
    
    
    
    return 0;
}