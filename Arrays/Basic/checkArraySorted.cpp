#include "bits/stdc++.h"
using namespace std;
// Problem Statement
/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.*/

// Approach- there is atmax 1 drop(nums[i]>nums[i+1]) in sorted rotated array that is either with last and first element or between the elements.Just check the drop and move ahead
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    bool ans=true;
    int count=((nums[0]<nums[nums.size()-1])?1:0);
    for (int i = 0; i < nums.size(); i++)
    {
        if(count>1){
            ans=false;
        }
        if(nums[i]>nums[(i+1)%nums.size()]) count++;
    }
    cout<<ans<<endl;
    return 0;
}
