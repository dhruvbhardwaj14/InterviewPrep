#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.*/
/*Approach- if arrays are sorted then compare each element of both array and using two pointer move ahead with element which is smaller*/
int main(){
     int n,m;
    cin>>n>>m;
    vector<long long int> a(n);
    vector<long long int> b(m);
    vector<long long int> c;
    for (long long int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (long long int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    long long int idxa=0;
    long long int idxb=0;

    while (idxa<a.size() && idxb<b.size())
    {
        if(a[idxa]<=b[idxb]){
            if(c.empty() || c.back() != a[idxa]){
                c.push_back(a[idxa]);
            }
            idxa++;
        }
        else{
            if(c.empty() || c.back() != b[idxb]){
                c.push_back(b[idxb]);
            }
            idxb++;
        }
    }
    while (idxb<b.size())
    {
        if(c.empty() || c.back() != b[idxb]){
        c.push_back(b[idxb]);
        }
        idxb++;
    }
    while (idxa<a.size())
    {
        if(c.empty() || c.back() != a[idxa]){
        c.push_back(a[idxa]);
        }
        idxa++;
    }
    for (auto &&i : c)
    {
        cout<<i<<" ";
    }
    
    return 0;
}