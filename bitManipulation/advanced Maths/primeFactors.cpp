#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a number N. Find its unique prime factors in increasing order.
Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
*/
/*Approach-
run loop from 2 to swrt(N) and if N is divisible by any number add to list and then  keep dividing untill N no more divisible by that number and move ahead
at end if N is not 1 add N to the answer as N may not have become 1 means it's a prime number
*/
vector<int> AllPrimeFactors(int N) {
    vector<int> ans;
    for (int i = 2; i <= sqrt(N); i++)
    {
        if(N%i==0){
            ans.push_back(i);
            while (N%i==0)
            {
                N=N/i;
            }
        }
    }
    if(N!=1){
        ans.push_back(N);
    }
    return ans;
    
}
int main(){
  
    return 0;
}