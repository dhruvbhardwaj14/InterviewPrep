#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
 
The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.*/
/*Approach- 
1.Skip all leading whitespaces.
2.Check for an optional sign (+ or -) and store it.
3.Initialize result as 0, and read digits one by one.
4.For each digit, update result: result = result * 10 + digit.
5.If result exceeds 32-bit signed int range, clamp to INT_MIN or INT_MAX.
6.Return result multiplied by sign (+1 or -1).
*/
int myAtoi(string s) {
    int i = 0;
    int n = s.length();
    long ans = 0; // use long to detect overflow
    int sign = 1;

    // 1. Skip leading whitespaces
    while (i < n && s[i] == ' ') i++;

    // 2. Handle sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. Convert digits
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';
        ans = ans * 10 + digit;

        // 4. Clamp to 32-bit signed int range
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;

        i++;
    }

    return static_cast<int>(ans * sign);//to explicitly convert the result from long back to int before returning it.
}
int main(){
  
    return 0;
}