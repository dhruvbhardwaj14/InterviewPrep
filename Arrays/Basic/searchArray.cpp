#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.*/
/*Approach- binary search on array*/
int main(){
     int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int s=0;
    int e=arr.size();
    while (s<=e) 
    {
        int mid=(s+e)/2;
        if(arr[mid]==k){
            cout<<true<<endl;
            return 0;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<false<<endl;
    return 0;
}