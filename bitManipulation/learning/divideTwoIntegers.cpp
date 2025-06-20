#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.*/

/*
Approach- 
Approach to Integer Division Without Using /, \*, or %:
1. Edge Case Handling:
   * If dividend == INT\_MIN and divisor == -1, return INT\_MAX to avoid overflow.
   * If dividend == divisor, return 1 directly.
2. Determine Result Sign:
   * Use a boolean 'sign':
     * If dividend and divisor have the same sign, the result is positive.
     * If they have opposite signs, the result is negative.
3. Convert to Positive Longs:
   * Cast both dividend and divisor to long to avoid overflow.
   * Take absolute values of both.
4. Bitwise Division Loop:
   * While numerator (n) >= denominator (d):
     * Use a counter (cnt) to find the highest power such that (d << (cnt + 1)) <= n.
     * This finds how many times (d \* 2^cnt) fits into n.
     * Add (1 << cnt) to the answer.
     * Subtract (d \* (1 << cnt)) from n.
5. Return Final Result:
   * If sign is positive, return the answer.
   * If sign is negative, return -answer.
Time Complexity:
* O(log² N), where N is the dividend.
  * Outer loop runs log N times.
  * Inner loop (to find cnt) also runs log N times in worst case.

*/
int divide(int dividend, int divisor) {
    // Handle overflow edge case explicitly
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    if(dividend == divisor) return 1;

    bool sign = true; // true means +ve
    if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        sign = false;

    long n = abs((long)dividend); // numerator
    long d = abs((long)divisor);  // denominator
    long ans = 0;

    while (n >= d) {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) {
            cnt++;
        }
        ans += 1L << cnt;
        n = n - (d * (1L << cnt));
    }

    return sign ? ans : -ans;
}    
int main(){

    return 0;
}