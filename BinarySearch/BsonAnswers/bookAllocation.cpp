#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.
*/
/*Approach- 
1. mid- denotes the number of pages allocated in range max to sum of arr
2. for each mid check if how many students can be allocated
3. if students allocated are lesser than required that means we need to minimize mid so hi=mid-1 and store ans
4. else move lo=mid+1 and repeat
*/
int countStudents(vector<int>& arr,int mid){
    int st=1,pagesStudent=0;
    for(int i=0;i<arr.size();i++){
        if(pagesStudent+arr[i]<=mid){
            pagesStudent+=arr[i];
        }
        else{
            st++;
            pagesStudent=arr[i];
        }
    }
    return st;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    if(n<m) return -1;
    else{
        int lo=*max_element(arr.begin(),arr.end());
        int hi=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(lo<=hi){
            int mid=lo+((hi-lo)/2);
            int cntStu=countStudents(arr,mid);
            if(cntStu>m){
                lo=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}