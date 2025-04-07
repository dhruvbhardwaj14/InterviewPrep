#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.*/
/*Approach- 
mid- kth positive integer
first of all normal 1dBS or bS on answers won't work here.
we have to find that for each mid what actual numbers are missing in array on that index.
we can determine that by difference of actual arr[mid]-mid (that was expected) now if missing numbers are more than k then we eliminate right half and if lesser then we eliminate left half
in the end hi<lo and hi points the lower missing number index and lo points to higher missing number index
this answer will be arr[hi]+more
more=k-(arr[high]-(high+1))
ans= arr[hi]+k-arr[hi]+high+1
ans=k+hi+1;
*/
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int lo=0,hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        int missing=arr[mid]-(mid+1);
        if(missing<k) lo=mid+1;
        else hi=mid-1;
    }
    cout<<hi+k+1<<endl;
    return 0;
}