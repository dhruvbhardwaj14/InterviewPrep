#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick
*/
/*Approach- 
1. Take two pointers l , r , map<int,int>, maxLen
2. start from l=0,r=0 and add fruits[r] to mp and check it's length
-> if length <=2 it's fine increase maxlen and r++
-> it's not fine now increment l untill map again has only 2 elements
repeat untill r<n

tc->O(2N)
sc->O(3)
// optimisation 

*/
// int totalFruit(vector<int>& fruits) {
//     int l=0,r=0,maxlen=0;
//     map<int,int> mp;
//     while (r<fruits.size())
//     {
//         mp[fruits[r]]++;
//         if(mp.size()<=2){
//             maxlen=max(maxlen,r-l+1);
//         }
//         else{
//             while (mp.size()>2)
//             {
//                 mp[fruits[l]]--;
//                 if(mp[fruits[l]]==0) mp.erase(fruits[l]);
//                 l++;
//             }
//         }
//         r++;
//     }
//     return maxlen;
    
// }

// Optimised version-> if map size increases then fix that window size and keep moving until you again get map size <=2
int totalFruit(vector<int>& fruits) {
    int l=0,r=0,maxlen=0;
    map<int,int> mp;
    while (r<fruits.size())
    {
        mp[fruits[r]]++;
        if(mp.size()>2){
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0) mp.erase(fruits[l]);
            l++;
        }
        if(mp.size()<=2){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
int main(){
  
    return 0;
}