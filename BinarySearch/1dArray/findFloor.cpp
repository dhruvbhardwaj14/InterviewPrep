#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.*/
/*Approach- implement lowerbound functionality of stl*/
int main(){
    int x,n;
    cin>> n>>x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int lo=0,hi=arr.size()-1,ans=-1;
    while(lo<=hi){
            int mid=lo+((hi-lo)/2);
            if(arr[mid]>x) {hi=mid-1;}
            else {ans=mid;lo=mid+1;}
    }
    cout<<ans<<endl;
    return 0;
}