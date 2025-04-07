#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/
/*
Approach- 
1. the mid represents the number of bananas to eat
2. In piles array start a range from 1 to max of piles and check for mid that how much hours it takes and if calculated hours more than given then definitely we need to increase number of bananas so move right and if not then move left and store in ans
*/
int calcHours(vector<int>& piles,int mid){
    int ans=0;
    for(int i=0;i<piles.size();i++){
        if(piles[i]<=mid) ans+=1;
        else
        if(piles[i]%mid==0) ans+=piles[i]/mid;
        else ans+=(piles[i]/mid)+1;
    }
    return ans;
}
int main(){
    int n,h;
    cin>>n>>h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin>>piles[i];
    }
    sort(piles.begin(),piles.end());
    int lo=1,hi=piles[n-1];
    int ans=0;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(calcHours(piles,mid)>h){
            lo=mid+1;
        }
        else if(calcHours(piles,mid)<=h){
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}