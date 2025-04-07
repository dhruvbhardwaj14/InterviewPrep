#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
we don't need it to be in place
Constraints:

2 <= nums.length <= 2 * 105
nums.length is even
1 <= |nums[i]| <= 10^5
nums consists of equal number of positive and negative integers.
*/
/*Approach- create a new array ans and place all positive elements of num in 0,2,4,6,8 positions and negative at 1,3,5,7,9*/
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int pos=0;
    int neg=1;
    bool flag=false;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]<0){
            ans[neg]=nums[i];
            neg+=2;
        }
        else{
            ans[pos]=nums[i];
            pos+=2;
        }
    }
    for (auto it : ans)
    {
        cout<<it<<" ";
    }
    
    
    
    
    return 0;
}
// -2 4 1 -5 3 5
// ->0  4 -2 1 -5 3 5 
// ->1  