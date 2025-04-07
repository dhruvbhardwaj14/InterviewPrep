#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.*/
/*Approach- 
Bs on Answers to find min(max) or max(min)
mid- denote the distance value by which it is possible to allocate all k cows in our x
*/
bool canPlace(vector<int> x,int mid,int k){
    int cnt=1;
    int lastIdx=x[0];
    for (int i = 0; i < x.size(); i++)
    {
        if(x[i]-lastIdx >=mid){
            cnt++;
            lastIdx=x[i];
        }
    }
    return (cnt>=k) ;
    
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int> x(n);
        for (int i = 0; i < n; i++)
        {
            cin>>x[i];
        }
        sort(x.begin(),x.end());
        int lo=1,hi=x[x.size()-1]-x[0],ans=1;
        while (lo<=hi)
        {
            int mid=lo+((hi-lo)/2);
            if(canPlace(x,mid,c)){
                lo=mid+1;
                ans=mid;
            }
            else{
                hi=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}