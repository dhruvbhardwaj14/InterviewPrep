#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given value n remove the last set bit (rightmost set bit)*/
/*Approach- 
n=16-> 1 0 0 0 0
n-1=15-> 0 1 1 1 1

n=84->1010100
n-1=83->1010011
n-1 is nothing but the number obtained by clearing right most set bit and all zeros to right of that bit will convert to 1
so just to removeRightmostSetBit just do n & n-1
*/
void removeRightmostSetBit(int& n){
    n=n&(n-1);
    return;
}
int main(){
    int n;
    cin>>n;
    removeRightmostSetBit(n);
    cout<<n<<endl;
    return 0;
}