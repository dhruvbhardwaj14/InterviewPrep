#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.*/
/*Approach- similar to find median of two sorted arrays but here find kth element so:-
1. left is now 'k'
2. lo is either 0 or atleast k-n2(bigger array elements) max of both
3. hi is either atleast k or upto  n1; min of both
*/
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1=a.size();
    int n2=b.size();
    if(n1>n2) return kthElement(b,a,k);
    int n=n1+n2;
    int left=k;
    int lo=max(0,k-n2),hi=min(k,n1);
    while(lo<=hi){
        int mid1=(lo+hi)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN;
        int r1=INT_MAX;
        int l2=INT_MIN;
        int r2=INT_MAX;
        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            hi=mid1-1;
        }
        else{
            lo=mid1+1;
        }
    }
    return 0;
}
int main(){
    int n1,n2,k;
    cin>>n1>>n2>>k;
    vector<int> nums1(n1);
    vector<int> nums2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin>>nums1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin>>nums2[i];
    }
    cout<<kthElement(nums1,nums2,k)<<endl;
    return 0;
}