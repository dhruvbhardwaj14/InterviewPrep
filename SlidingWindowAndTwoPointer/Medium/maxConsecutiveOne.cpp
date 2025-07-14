#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/
/*Approach- 
1. Use two pointers `l` and `r` to maintain a sliding window over the array.
2. Keep track of the number of zeros (`cntZer`) in the current window.
3. If the number of zeros exceeds `k`, shrink the window from the left until `cntZer <= k`.
4. For every valid window (with at most `k` zeros), update `maxlen` with the window size `r - l`.
5. Move the right pointer `r` forward each time to expand the window.
6. Return the maximum window length found.

*/
int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,cntZer=0,maxlen=0;
        while (r<n)
        {
            if(!nums[r]){
                cntZer++;
            }
            if(cntZer>k){
                if(nums[l]==0){
                    cntZer--;
                }
                l++;
            }
            if(cntZer<=k){
                maxlen=max(maxlen,(r-l));//since r already incremented
            }
            r++;
        }
        return maxlen;
}
int main(){
  
    return 0;
}