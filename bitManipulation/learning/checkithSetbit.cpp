#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*check if the ith bit is set or not for a int without converting it into binary */
/*Approach-
1<<i= 1(ith place) 0 0 0 0 .... till 0th bit
x-> 1 0 1
1<<1->0 1 0
&-> 0 0 0-> false
*/
bool checkithSet(int x,int i){
    // return ((x)&(1<<i));//left shift
    return (x>>i)&1;
}
int main(){
    int n,i;
    cin>>n>>i;
    if(checkithSet(n,i)){
        cout<<"Yes the "<<i<<"th bit is set.";
    }
    else{
        cout<<"No the "<<i<<"th bit is not set.";
    }
    return 0;
}