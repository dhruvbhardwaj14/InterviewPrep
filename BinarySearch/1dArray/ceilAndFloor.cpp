#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
*/
/*Approach- simply iterate in the array and find ceil and floor*/
int main(){
    int x,n;
    cin>> n>>x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int g_mn=INT_MAX,g_mx=INT_MIN;
        int mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            g_mn=min(arr[i],g_mn);
            g_mx=max(arr[i],g_mx);
            if(arr[i]==x) {mn=arr[i];mx=arr[i];}
            else if(arr[i]>x){
                mn=min(arr[i],mn);
            }
            else if(arr[i]<x){
                mx=max(arr[i],mx);
            }
        }
        
        if(x>g_mx){
            cout<<mx<<-1<<endl;
        }
        else if(x<g_mn){
            cout<<-1<<mn<<endl;
        }
        else cout<<mx<<mn<<endl;
    return 0;
}