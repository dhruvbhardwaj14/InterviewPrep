#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*swap without using xor operator*/
/*Approach- 
a=a^b
b=a^b=a^b^b=a
a=a^b=a^b^a=b
*/
void swap(int& a,int& b){
    a=a^b;
    b=a^b;
    a=a^b;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"a: "<<a<<" b:"<<b<<endl;
    swap(a,b);
    cout<<"a: "<<a<<" b:"<<b;
    return 0;
}