#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Can you come up with an algorithm that is less than O(n^2) time complexity?

Constraints:
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

// Here the better approach with map is best only if indices of the sum pair is asked and optimal is best if only yes or no is asked that if the sum exist or not

/*Better Approach- make a hashmap of all the elements in the array with (element,index) pair and now iterate in array and find if (target-value) exist in hashmap and if that exists return the indices if not then move ahead*/

/*Optimal Approach(without map) - sort the array and make two pointers and start one from beginning and other from end and find their sum. If sum> target then endpointer-- if sum<target then startpointer++ and if sum=target return yes else if start>end then return no (from the original array)*/
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> nums(n);
    vector<int> ans;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
        mp[nums[i]]=i;
    }
    for (int i = 0; i < n; i++)
    {
        if(mp.find(target-nums[i])!=mp.end()){
            ans.push_back(i);
            ans.push_back(mp[target-nums[i]]);
            break;
        };
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}