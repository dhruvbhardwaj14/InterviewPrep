#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*fibonacci with DP*/
/*Approach-
memoization
-> we tend to store the value of subproblems in some map/table
-> go from required answer to base case and come back

Tabulation
-> bottom up
-> try to go from base case to required answer
*/

// memoization-> TC(O(n)) SC(O(n)+stack space for recursion)
// int fibo(int n,vector<int>& dp){
//     if(n<=1){
//         return n;
//     }
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
// }

// tabulation-> TC(O(n)) SC(O(n)) no stack space
int fibo(int n,vector<int>& dp){
    dp[0]=0;dp[1]=1;
    for (int i = 2; i <=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//  Optimised -> TC(O(n)) SC(O(1))
int fiboOptimised(int n){
    int prev_1=1,prev_2=0;
    for (int i = 2; i <=n; i++)
    {
        int curi=prev_1+prev_2;
        prev_2=prev_1;
        prev_1=curi;
    }
    return prev_1;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibo(n,dp)<<endl;
    cout<<fiboOptimised(n)<<endl;
    return 0;
}