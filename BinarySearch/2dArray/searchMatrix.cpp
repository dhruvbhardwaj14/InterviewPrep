#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/
/*Approach- 
int i = k / n;  // Row index
int j = k % n;  // Column index
k is the 1D index ranging from 0 to m * n - 1
and apply binary search in range 0 to m*n-1;
*/
int main(){
    int m,n,target;
    cin>>m>>n>>target;
    vector<vector<int>> matrix(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cin>>matrix[i][j];
        }
    }
    int lo=0,hi=m*n-1;
    bool ans=false;
    while (lo<=hi)
    {
        int mid=(hi+lo)>>1;
        if(matrix[mid/n][mid%n]==target){
            ans=true;
            break;
        }
        else if(matrix[mid/n][mid%n]>target){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}