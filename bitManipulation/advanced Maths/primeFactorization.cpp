#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given a positive number N. Using the concept of Sieve, compute its prime factorisation

Expected Time Complexity: O(Nlog(log(N)).
Expected Auxiliary Space: O(N)
*/
/*Approach- 
Precompute-> find the smallest prime factor that divides n in an array[n] using sieve

for any given n look at value at arr[n] and divide by it
for the resultant do same until it reaches 1/
*/


vector<int> findPrimeFactors(int N) {
    // sieve of erastosthenes
    int n=N;
    int arr[n+1];
    for (int i = 2; i <=n; i++)
    {
        arr[i]=i;//mark them as their own number initially
    }
    for (int i = 2; i <=n; i++)
    {
        if(arr[i]==i){
            int j=2;
            while (i*j<=n)
            {
                if(arr[i*j]==i*j){
                    arr[i*j]=i;
                }
                j++;
            }
        }
    }
    // main code here
    vector<int> ans;
    while (N>1)
    {
        ans.push_back(arr[N]);
        N/=arr[N];
    }
    return ans;
    
}
int main(){
  
    return 0;
}