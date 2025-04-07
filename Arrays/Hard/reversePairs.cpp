#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
*/
/*Approach- 
Similar to mergesort but here before using merge we use a countpairs function that count the pairs before the arrays are merged
*/
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;     
    int right = mid + 1;   
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }

        // right is smaller
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int>&arr ,int low,int mid ,int high){
    int right=mid+1;
    int cnt=0;
    for (int i = low; i <=mid; i++)
    {
        while (right<=high and (long long)arr[i] > 2LL * arr[right]) right++;
        {
            cnt+=(right-(mid+1));
        }
    }
    return cnt;
    
}
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt=0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt+=mergeSort(arr, low, mid);  // left half
    cnt+=mergeSort(arr, mid + 1, high); // right half
    cnt+=countPairs(arr,low,mid,high);
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<mergeSort(arr,0,arr.size()-1)<<endl;
    return 0;
}