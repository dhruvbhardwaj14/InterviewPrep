#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

*/
/*Approach- 
1. Binary search will determine whether a combination (i.e. 2 elements from array 1 and 3 elements from array 2 are on left half of the median in case of total 10 elements in both combined) forms a symmetry
arr1->1,3,4,7,10,12
arr2-> 2 3 6 15
2. Check if symmetry valid only check cross elements for ex left half-> 1 3 4(arr1) 2 3(arr2) | right half-> 7 10 12(arr1) and 6 15(arr2)
2.1 so compare if last element of arr1 on left half is smaller than first element of arr2 on right half i.e 4<6 AND 
if last element of arr2 on left half is smaller than first element of arr1 on right half
3. if both conditions justify that means we have got the correct order of symmetry
4. find median two elements by taking maxof(left half last elements of arr1 and arr2) and taking minod\f(right half first elements of arr1 and arr2)
5. if n=even then median=sum of these elements/2 and if n=odd then median=maxof element


finding the binary search pattern in this
----ONLY IF TOTAL ELEMENTS ARE EVEN------
1. initially take whole arr1(consider arr1 is shorter length array) as part of our left half and eliminate left or right half based on the last element of arr1 is either greater or smaller than first element of arr 2
let name these elements as l1,l2,r1,r2
if l1>r2 hi=mid-1;
if l2>r1 lo=mid+1;

binary search in progress
range- [0,sizeof(arr1)];
1. mid1- from arr1 how many we have to pick
2. mid2- from arr2 how many we have to pick(total-mid1 )
3. mid1 and mid2 both lie on the right half of symmetry always that means r1=arr[mid1] and r2=arr[mid2] and l1=arr[mid1-1], l2=arr[mid2-1]
4. median is (max(l1,l2)+min(r1,r2))/2

----IF TOTAL ELEMENTS ARE ODD------
if n1+n2-> odd 
then take (n1+n2+1)/2 elements on left half
median max(l1,l2)
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1>n2){
        return findMedianSortedArrays(nums2,nums1);
    }
    int n=n1+n2;
    int left=(n+1)/2;
    int lo=0,hi=n1;
    while(lo<=hi){
        int mid1=lo+((hi-lo)/2);
        int mid2=left-mid1;
        int l1=INT_MIN;
        int r1=INT_MAX;
        int l2=INT_MIN;
        int r2=INT_MAX;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n&1) return max(l1,l2);
            else return (double)((max(l1,l2)+min(r1,r2))/2.0);
        }
        else if(l1>r2) hi=mid1-1;
        else lo=mid1+1;
    }
    return 0.0;
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> nums1(n1);
    vector<int> nums2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin>>nums1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin>>nums2[i];
    }
    cout<<findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}