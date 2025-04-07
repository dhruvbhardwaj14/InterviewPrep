#include "bits/stdc++.h"
using namespace std;
// Problem Statement 
/* Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.*/

// Approach- largest is compared and whenever it is updated we take the current largest to second largest. Also if an element is smaller than largest but greater than second largest we update the values of secondLargest.
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int mx=arr[0];
    int scndmx=-1;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i]>mx){
            scndmx=mx;
            mx=arr[i];
        }
        else if(arr[i]<mx && arr[i]>scndmx){
            scndmx=arr[i];
        }
    }
    cout<<scndmx<<endl;
    
    return 0;
}
