#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer n count the number of set bits in it*/
/*Approach- 
/ /first approach -> divide n/2 each step and add to count if it is odd each time add 1[T.c.-> O(log2n)]
// other better approach -> until n becomes zero just remove rightmost bit from it and count that[T.c.-> O(no. of set bits)]
*/
void removeRightmostSetBit(int& n){
    n=n&(n-1);
    return;
}
int countSetBits(int n){
    int count=0;
    while (n)
    {
        removeRightmostSetBit(n);
        count++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<countSetBits(n)<<endl;
    return 0;
}