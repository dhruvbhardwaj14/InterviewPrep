#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*convert an int by 
-setting it's ith bit
-clearing it's ith bit
-toggling it's ith bit
*/
/*Approach- simple shown in function*/
void setithBit(int& n,int i){
    n=(n|(1<<i));//left shift
    return;
}
void clearithBit(int& n,int i){
    n=(n & ~(1<<i));//left shift
    return;
}
void toggleithBit(int& n,int i){
    n=(n ^ (1<<i));//left shift
    return;
}
int main(){
    int n,i;
    cin>>n>>i;
    setithBit(n,i);
    cout<<n<<endl;
    clearithBit(n,i);
    cout<<n<<endl;
    toggleithBit(n,i);
    cout<<n<<endl;
    
    return 0;
}