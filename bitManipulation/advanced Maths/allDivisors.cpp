#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an integer N, print all the divisors of N in the ascending order.

Expected Time Complexity: O(sqrt(N))
Expected Space Complexity: O(sqrt(N))
*/
/*Approach- 
run loop from 1 to N and if any number i divides the number n then n/i should also divide n
so run only till sqrt(n) and add to list
*/

void print_divisors(int n) {
    vector<int> firstdivisors;
    vector<int> seconddivisors;
    for (int i = 1; i <=sqrt(n); i++)
    {
        if(n%i==0){
            firstdivisors.push_back(i);
            if(n/i!=i)seconddivisors.push_back(n/i);
        }
    }
    reverse(seconddivisors.begin(),seconddivisors.end());
    firstdivisors.insert(firstdivisors.end(), seconddivisors.begin(), seconddivisors.end());
    for (int i = 0; i < firstdivisors.size(); i++)
    {
        cout<<firstdivisors[i]<<" ";
    }
    
}
int main(){
  
    return 0;
}