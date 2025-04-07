#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.*/
/*Approach-
let's say we have array [3,3,7,7,10,11,11] now a single element will have it's previous and next element as different while a current duplicate element will have either of it as same. We see a trend that if (idx,idx+1) are :-
1. (even,odd) index -> that means single element is on right half - lo=mid+1
2. (odd,even) index -> that means element on left half- hi=mid-1
repeat 
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    if(nums.size()==1) return nums[0];
        if(nums[1]!=nums[0]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int lo=1,hi=nums.size()-2;
        while(lo<=hi){
            int mid=lo+((hi-lo)/2);
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                cout<<nums[mid]<<endl;
                return 0;
            }
            else{
                if(mid&1){
                    if(nums[mid]==nums[mid+1]){
                        hi=mid-1;
                    }
                    else{
                        lo=mid+1;
                    }
                }
                else{
                    if(nums[mid]==nums[mid+1]){
                        lo=mid+1;
                    }
                    else{
                        hi=mid-1;
                    }
                }
            }
        }
    cout<<-1<<endl;
    return 0;
}