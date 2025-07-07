#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.*/
/*Approach-
1. since we to find how much water is trapped first of all we will define the amount of water any building of height height[i] holds over it's head will be:-
-> if there is a larger building on left of it->lmax
-> if there is a larger building on right of it->rmax
if height[i]<lmax and height<rmax then it's water content will be= min(lmax ,rmax)-height[i];
2. To remove this min factor what we will do is we move ahead using two pointers r and l
-> if height[l]<=height[r] we are basically having lmax as min of two so we have find water content by lmax-height[l] and l++ move ahead
-> else by rmax-height[r] and r-- move ahead until l<r
*/
int trap(vector<int>& height) {
    int ans;
    int l=height[0];
    int r=height[height.size()-1];
    int lmax=0,rmax=0,total=0;
    while (l<r)
    {
        if(height[l]<=height[r]){
            if(lmax>height[l]){
                total+=lmax-height[l];
            }
            else{
                lmax=height[l];
            }
            l++;
        }
        else{
            if(rmax>height[r]){
                total+=rmax-height[r];
            }
            else{
                rmax=height[r];
            }
            r++;
        }
    }
    return ans;
    
}
int main(){
  
    return 0;
}