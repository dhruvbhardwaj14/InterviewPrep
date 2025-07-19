#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/
/*Approach- 
1. Define a helper function that takes the base x and the exponent n as parameters, where n is of type long long to safely handle large negative inputs.

2. In the helper function, set the base case: if n equals 0, return 1.0.

3. Recursively compute half = helper(x, n / 2).

4. If n is even, return half multiplied by half.

5. If n is odd, return x multiplied by half multiplied by half.

6. In the main function, declare a variable N of type long long and assign it the value of the input exponent n.

7. Check if N is negative. If it is, mark a boolean isNeg as true and convert N to its absolute value using abs(N).

8. Call the helper function with x and the absolute value N to get the result.

9. If isNeg is true, return 1.0 divided by the result. Otherwise, return the result directly.

*/
double helper(double x, int n){
    if(x==1.0 || n==0){
        return 1.0;
    }
    double half = helper(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}
double myPow(double x, int n) {
    long long N=n;
    bool isNegPower=(N<0);
    N=abs(N);
    double ans=helper(x,N);
    return (isNegPower)?1.0/ans:ans;
}
int main(){
  
    return 0;
}