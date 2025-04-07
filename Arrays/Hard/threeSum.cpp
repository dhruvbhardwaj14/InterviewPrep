#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/
/* Approach- 
1. sort the array given to us so that we can skip the duplicates
2. take 3 pointer i,j,k out of which i is fixed and j and k are moving. i->0 to n-1, j=i+1,k=n-1
3. for each nums[i] find the nums[j] and nums[k] which sum up to target(0)
4. to do this if sum>target then k-- and if sum<target then j++, if sum==target then push to vector res and k-- and j++ both untill duplicates are skipped.
*/
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    
    for (int i = 0; i < nums.size(); i++)
    {
        if(i>0 && nums[i-1]==nums[i]) continue;
        else{
            int j=i+1,k=nums.size()-1;
            while (j<k)
            {
                int ans=nums[i]+nums[j]+nums[k];
                if(ans==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    // skip duplicates
                    while (j<k && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                    while (j<k && nums[j-1]==nums[j])
                    {
                        j++;
                    }
                }
                else if(ans>0){
                        k--;
                }
                else{
                    j++;
                }
            }
        }
        
    }
    for (auto it : res)
    {
        for (auto v : it)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}