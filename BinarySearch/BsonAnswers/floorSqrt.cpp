#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number
1 ≤ n ≤  3 x 10^4
*/
/*Approach- go in search space integer wise from 1 to n/2 and check mid's square if it's square is greater than n then search left half and if it's square is smaller then search right half and store it somewhere*/
int main(){
    int n;
    cin>>n;
    int lo=1,hi=n/2,ans=0;
        while(lo<=hi){
            long long int mid=lo+((hi-lo)/2);
            if(mid*mid>n) hi=mid-1;
            else {
                ans=mid;
                lo=mid+1;
            }
        }
      cout<<ans<<endl;
    return 0;
}