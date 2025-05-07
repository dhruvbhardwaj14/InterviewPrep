#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.
*/
/*Approach- 
1. mid- denotes the time taken by painters in range max to sum of boards
2. for each mid check if how many painters can be allocated
3. if painters allocated are lesser than required that means we need to minimize mid so hi=mid-1 and store ans
4. else move lo=mid+1 and repeat
*/
int countPainters(vector<int>& arr,int mid){
    int pt=1,paintedArea=0;
    for(int i=0;i<arr.size();i++){
        if(paintedArea+arr[i]<=mid){
            paintedArea+=arr[i];
        }
        else{
            pt++;
            paintedArea=arr[i];
        }
    }
    return pt;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> boards(n);
    for (int i = 0; i < n; i++)
    {
        cin>>boards[i];
    }
    int lo=*max_element(boards.begin(),boards.end());
    int hi=accumulate(boards.begin(),boards.end(),0);
    int ans=0;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        int cntPt=countPainters(boards,mid);
        if(cntPt>k){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}