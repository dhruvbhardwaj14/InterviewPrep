#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 
*/
/*Approach- upperbound index-lowerbound index+1 gives frquency count of that number*/
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin()-1;
    cout<<((lb>=0 && ub<arr.size())?ub-lb+1:0)<<endl;
    return 0;
}