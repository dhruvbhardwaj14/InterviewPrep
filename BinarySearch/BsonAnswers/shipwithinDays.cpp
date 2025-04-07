#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/
/*
Approach- 
mid- weight capacity of ship 
calcdays for mid and if calculated day>days  given then definitely we need more threshold weight that is increase mid as lo=mid+1; else hi=mid-1 and save in ans;
*/
int calcDays(vector<int>& weights,int mid){
    int ans=1,sum=0,n=weights.size();
    for(int i=0;i<n;i++){
        if(weights[i]+sum>mid){
            ans++;
            sum=weights[i];
        }
        else{
            sum+=weights[i];
        }
    }
    return ans;
}
int main(){
    int n,days;
    cin>>n>>days;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin>>weights[i];
    }
    int mx=INT_MIN,sm=0;
    for(int i=0;i<weights.size();i++){
        mx=max(mx,weights[i]);
        sm+=weights[i];
    }
    int lo=mx,hi=sm,ans=0;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(calcDays(weights,mid)>days){
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