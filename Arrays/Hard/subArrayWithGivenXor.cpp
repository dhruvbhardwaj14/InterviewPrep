#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.
1 <= length of the array <= 10^5
1 <= A[i], B <= 10^9
*/
/*Approach- 
create a map<int,int> that stores the prefixXor till now and now iterate in array and check if target^current_xor exists in map if yes add it's occurence to count and if not then increment that count by 1

*/
int main(){
    int n1,B;
    cin>>n1>>B;
    vector<int> A(n1);
    for (int i = 0; i < n1; i++)
    {
        cin>>A[i];
    }
    int ans=0;
    int count=0;
    map<int,int> mp;
    mp[0]=1;
    for (int i = 0; i < n1; i++)
    {
        ans^=A[i];
        count+=mp[ans^B];
        mp[ans]++;
    }
    cout<<count<<endl;
    
    
    
    return 0;
}