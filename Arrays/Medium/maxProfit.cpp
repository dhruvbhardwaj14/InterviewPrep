#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

/*Approach - Find the min from 0 to i-1 on index i and find it's difference with prices[i] once done then store that difference in max variable as maximum of all the differences so far*/
int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin>>prices[i];
    }
    int mn=prices[0];
    int ans=0;

    for(int i=1;i<prices.size();i++){
        mn=min(mn,prices[i-1]);
        ans=max(ans,(prices[i]-mn));
    }
    cout<<ans<<endl;
    return 0;
}