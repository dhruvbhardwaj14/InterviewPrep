#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer array nums, find the subarray with the largest sum, and return its sum.

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Constraints:-
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/*Approach-
Kadane's algorithm-
take a sum=0 and max=INT_MIN variables and whenever sum<0 it means we won't carry forward it to the next portion that means the subarray is over then sum=0 and move to next element and always make sure you take max as max(max,sum) in each iteration
 */
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int sum=0;
    int mx=INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum+=nums[i];
        mx=max(sum,mx);
        if(sum<0){
            sum=0;
        }
    }
    cout<<mx<<endl;
    return 0;
}