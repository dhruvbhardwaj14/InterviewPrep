#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a binary array nums, return the maximum number of consecutive 1's in the array.*/
/*Approach- take  variables k and ans , k keeps count of number of consecutive one appearing while ans has maximum of those count */
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int k=0;
    int ans=INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==0){
            ans=max(ans,k);
            k=0;
        }
        else{
            k++;
        }
    }
    ans=max(ans,k);
    cout<<ans<<endl;
    return 0;
}
