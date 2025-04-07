#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

*/
/*
Approach- 
1. mid denotes the number of days taken to make the bouquets
2. for each mid calculate total number of bouqets we can make out of whole bloomday and if we get less than m then for right side and more than then store and go left side
*/
int calcBouqet(vector<int>& bloomDay, int mid, int k) {
    int bouquets = 0, flowers = 0;
    
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= mid) { // Flower can bloom
            flowers++;
            if (flowers == k) { // A full bouquet is formed
                bouquets++;
                flowers = 0; // Reset counter
            }
        } else {
            flowers = 0; // Reset because we need contiguous flowers
        }
    }

    return bouquets;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++)
    {
        cin>>bloomDay[i];
    }
    auto mx=max_element(bloomDay.begin(),bloomDay.end());
       int lo=1,hi=*mx,ans=0;;
       while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(calcBouqet(bloomDay,mid,k)<m){
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