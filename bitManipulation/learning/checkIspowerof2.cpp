#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.*/
/*Approach- if it is power of 2 then it's only 1 bit is set rest all unset 
n=16-> 1 0 0 0 0
n-1=15-> 0 1 1 1 1

n=84->1010100
n-1=83->1010011

so if n&n-1 is == 0 then yes it is a power of 2 else not
*/
bool isPowerOfTwo(int n) {
    if(n<=0) return false;//negative numbers
    return ((n&(n-1))==0);
}
int main(){
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n)<<endl;
    return 0;
}