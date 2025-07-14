#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.*/
/*Approach- 
1.take lsum , rsum 
2. lsum is sum of first k elements and rsum is 0
3. remove one element from last of lsum elements and add one element of rightmost to rsum and find total sum lsum+rsum and find max of all the sums till then
*/
int maxScore(vector<int>& cardPoints, int k) {
    int lsum=0,rsum=0,maxSum=0;
    for (int i = 0; i < k; i++)
    {
        lsum+=cardPoints[i];
    }
    maxSum=lsum;
    int rIndex=cardPoints.size()-1;
    for (int i = k-1; i >=0; i--)
    {
        lsum-=cardPoints[i];
        rsum+=cardPoints[rIndex];
        maxSum=max(lsum+rsum,maxSum);
        rIndex--;
    }
    return maxSum;
}
int main(){
  
    return 0;
}