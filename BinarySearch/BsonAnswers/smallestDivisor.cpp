#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.*/
/*Approach- 
mid- denotes the divisor we need to find
and sort the array and check the sum for mid, if sum is greater than threshold that means we need to narrow down the sum so mid needs to be more so that divisor sum is decreased hence lo=mid+1, but in contrary case take hi=mid-1 and store the ans;
*/
int calcSum(vector<int>& nums,int mid){
    int ans=0;
    for (int i = 0; i < nums.size(); i++)
    {
        int a=nums[i];
        int b=mid;   
        ans+=(a + b - 1) / b;
    }
    return ans;
}
int main(){
    int n,threshold;
    cin>>n>>threshold;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int lo=1,hi=nums[nums.size()-1], ans=0;
    while (lo<=hi)
    {
        int mid=lo+((hi-lo)/2);
        if(calcSum(nums,mid)>threshold){
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