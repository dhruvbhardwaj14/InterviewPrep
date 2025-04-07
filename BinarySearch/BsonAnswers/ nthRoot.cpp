#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.*/
/*Approach- simple square root approach just multiply mid n times*/
int nTimes(int x,int n){
    int ans=1;
    for (int i = 0; i < n; i++)
    {
        ans*=x;
    }
    return ans;
}
int main(){
    int n,m;
    cin>>m>>n;
    int lo=1,hi=m,ans=0;
        while(lo<=hi){
            long long int mid=lo+((hi-lo)/2);
            if(nTimes(mid,n)>m) hi=mid-1;
            else if(nTimes(mid,n)==m) {cout<<mid<<endl;return 0;}
            else {
                lo=mid+1;
            }
        }
      cout<<-1<<endl;
    return 0;
}