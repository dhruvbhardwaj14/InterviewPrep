#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

2 ≤ N ≤ 10^6
1 ≤ Arri ≤ 10^12
*/
/*Approach- 
-xor all numbers u will get a number as the ans to xor of all numbers (xo)
-for the two odd occurence numbers there is minimum 1 bit that is different
- now in the xor u found select the first set(1) bit let suppose it is at ith position
-- this signifies that the ith position in the two ans is going to be different for sure
- traverse the array and store all the numbers in any one of the two buckets 
1. Bucket1- if the ith bit of that number is 1
2. Bucket0 - if the ith bit of that number is 0
*/
vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int xo=Arr[0];
    for (long long int i = 1; i < N; i++)
    {
        xo^=Arr[i];
    }
    // to get the first set bit (rightmost set bit)-> remove rightmost set bit and then extract using xor
    long long int rtSetBit=((xo)&(xo-1))^xo;
    vector<long long int> bucket1;
    vector<long long int> bucket2;
    for (long long int i = 0; i < N; i++)
    {
        if(Arr[i]&rtSetBit){
            bucket1.push_back(Arr[i]);
        }
        else{
            bucket2.push_back(Arr[i]);
        }
    }
    long long int num1=bucket1[0];
    long long int num2=bucket2[0];
    for (long long int i = 1; i < bucket1.size(); i++)
    {
        num1^=bucket1[i];
    }
    for (long long int i = 1; i < bucket2.size(); i++)
    {
        num2^=bucket2[i];
    }
    return ((num1>num2)? vector<long long int>{num1,num2} :vector<long long int>{num2,num1});
    
    
}
int main(){
  
    return 0;
}