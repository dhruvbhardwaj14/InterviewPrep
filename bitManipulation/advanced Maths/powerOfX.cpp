#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/
/*Approach-
1. Take a variable ans as 1
2. whenever power is odd-> take 1 from the power and multiply ans with x
3. whenever power is even-> square the given x and divide power by 2
*/
double myPow(double x, int n) {
    long long N = n; // Convert to long long to handle INT_MIN
    bool isNeg = (N < 0);
    if (N == 0 || x == 1.0) {
        return 1.0;
    }

    N = abs(N); // Now safe to use abs

    double ans = 1;
    while (N > 0) {
        if (N % 2 == 1) {
            ans *= x;
            N--;
        } else {
            x *= x;
            N /= 2;
        }
    }

    return isNeg ? 1.0 / ans : ans;
}
int main(){
  
    return 0;
}