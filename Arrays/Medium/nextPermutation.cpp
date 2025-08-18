#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/
// Note- Learn how to generate all permutations of a given array using recursion as well as normal iteration
/*
Approach- 
1. First we need to figure out the breakpoint that where the permutation's next will be different from like in 2 3 1
the breakpoint is before 3 as at 3 the maximum number is found and before that all numbers will be same and after that will be rearranged  in ascending orer
2. find the smallest number greater than the breakpoint i.e. 2  on right of our breakpoint i.e. 3 
3. replace the breakpoint with that number therefore 3 _ _ and then add the rest numbers in sorted order i.e. 3 1 2
4. that will get us the next permutation 
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int idx=-1;
    int ind=-1;
    int mn=INT_MAX;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(nums.begin(),nums.end());
    }
    else{
        for (int i = n-1; i>idx; i--)
        {
            if(nums[i]>nums[idx]){
                if(mn>nums[i]){
                    mn=nums[i];
                    ind=i;
                }
            }
        }
        swap(nums[idx],nums[ind]);
        reverse(nums.begin()+idx+1,nums.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}