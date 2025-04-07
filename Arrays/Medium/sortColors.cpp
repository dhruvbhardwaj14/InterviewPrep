#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Could you come up with a one-pass algorithm using only constant extra space?
*/


/*Approach- 
DUTCH NATIONAL FLAG ALGORITHM
take three pointer low,mid,high and follow these rules always
1. array from 0 to low-1 is always sorted with 0s
2. array from low to mid-1 is always sorted with 1s
3. array from high+1 to n-1 is always sorted with 2s
4. array from mid to high is our unsorted array

now take low=0,mid=0,high=n-1 and make a while loop until mid<high
- if a[mid]==0, swap(a[mid],a[low]),mid++,low++
- if a[mid]==1, mid++
-if a[mid]==2, swap(a[mid],a[high]),high--
*/
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int low=0;
    int high=nums.size()-1;
    int mid=0;
    while (mid<=high)
    {
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    for (auto it : nums)
    {
        cout<<it<<" ";
    }
    return 0;

}
/* 
1 2 0 0 1 2 0
0 2 1 0 1 2 0
0 0 1 2 1 2 0
0 0 0 2 1 2 1
0 0 0 1 1 2 2 
*/
