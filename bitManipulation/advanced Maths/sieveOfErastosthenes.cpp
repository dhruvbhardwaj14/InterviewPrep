#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer n, return the number of prime numbers that are strictly less than n.
*/
/*Approach- 
Precomputation
    for given n
    make a array from 2 to n and mark all as 1
    now in array start from 2 and mark all it's multiples as 0 since they cannot be prime
    move to next 1 in array and do same

main code
visit from 2 to n and if arr[i] is 1 increment count and return it
*/
int countPrimes(int n) {
    if(n<=2) return 0;
    // sieve of erastosthenes
    int arr[n+1];
    for (int i = 2; i <=n; i++)
    {
        arr[i]=1;
    }
    for (int i = 2; i <=n; i++)
    {
        if(arr[i]==1){
            int j=2;
            while (i*j<=n)
            {
                arr[i*j]=0;
                j++;
            }
        }
    }

    // main code
    int count=0;
    for (int i = 2; i <n; i++)
    {
        if(arr[i]==1) count++;
    }
    return count;

}
int main(){
  
    return 0;
}