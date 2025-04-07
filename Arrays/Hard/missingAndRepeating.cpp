#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.

Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].
*/
/*Approach- 
Let Y be repeating number and X be missing number then we know 
1. Sum of first n elements(let expected_sum) is n*n+1/2 but our Sum has X and not y so this implies that expected_sum-sum = Y-x;
2. similarly sum of square of first n elements (let expected_square_sum) will give us a a equation that is expected_square_sum-squareSum= Y^2-X^2 or (y-x)(y+x) 
3.Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),Here, X-Y = eq1 and X+Y = eq2:
*/
int main(){
    long long int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long int expected_sum=(n*(n+1))/2;
    long long int expected_square_sum=(n*(n+1)*((2*n)+1))/6;
    long long int sum=0;
    long long int squareSum=0;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
        squareSum=squareSum+((long long) arr[i]* (long long)arr[i]);
    }
    //X-Y:
    long long int eq1=expected_sum-sum;
    //X^2-Y^2:
    long long int eq2=expected_square_sum-squareSum;
    // X+Y = (X^2-Y^2)/(X-Y):
    eq2=eq2/eq1;
    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long int x=(eq1+eq2)/2;
    long long int y=x-eq1;
    cout<<x<<" "<<y;
    return 0;


}