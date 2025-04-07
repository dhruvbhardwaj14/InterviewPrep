#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
/*Approach- 
1. sort the array given to us so that we can skip the duplicates
2. take 4 pointer i,j,k,l out of which i is fixed and j and k are moving. i->0 to n-1,j->i+1 to n-1, k=j+1,l=n-1
3. for each nums[i] and the nums[j] find nums[k], nums[l] which sum up to target
4. to do this if sum>target then k-- and if sum<target then j++, if sum==target then push to vector res and k-- and j++ both untill duplicates are skipped.
*/
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i+1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k=j+1;
            int l=nums.size()-1;
            while (k<l)
            {
                int ans=nums[i]+nums[j]+nums[k]+nums[l];
                if(ans==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    res.push_back(temp);
                    k++;
                    l--;
                    //skip the duplicates
                    while (k<l && nums[k]==nums[k-1])
                    {
                        k++;
                    }
                    while (k<l && nums[l]==nums[l+1])
                    {
                        l--;
                    }  
                }
                else if(ans>target){
                    l--;
                }
                else{
                    k++;
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