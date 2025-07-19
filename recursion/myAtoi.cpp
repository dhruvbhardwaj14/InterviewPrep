#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.
*/
/*Approach- 
1. Start by defining a recursive helper function that takes the string, current index, accumulated answer (as long long), and the sign as arguments.
2. In the main function, initialize an index variable to zero.
3. Skip all leading whitespaces by incrementing the index while the current character is a space.
4. After whitespace, check if the next character is a sign (`+` or `-`). If it's `-`, set sign = -1. If it's `+` or `-`, increment the index.
5. Call the helper function with initial answer as 0, current index, and the determined sign.
6. In the helper function, if the index has reached the end of the string or the current character is not a digit, return sign multiplied by answer (cast to int).
7. Convert the current character to a digit by subtracting `'0'`.
8. Before updating the answer, check if `answer > (INT_MAX - digit) / 10`. If true, return INT\_MAX if sign is positive, or INT\_MIN if sign is negative.
9. Multiply the current answer by 10 and add the digit.
10. Recursively call the helper function with index incremented by one and updated answer.
11. Return the final result from the main function.
*/
// int myAtoi(string s) {
//     bool isNeg = false;
//     int i = 0;
//     int n = s.length();
//     long long ans = 0;

//     // Skip leading whitespaces
//     while (i < n && s[i] == ' ') i++;

//     // Sign
//     if (i < n && (s[i] == '-' || s[i] == '+')) {
//         isNeg = (s[i] == '-');
//         i++;
//     }

//     // Process digits
//     while (i < n && isdigit(s[i])) {
//         int digit = s[i] - '0';

//         ans = ans * 10 + digit;

//         // Clamp immediately
//         if (!isNeg && ans >= (long long)INT_MAX) return INT_MAX;
//         if (isNeg && -ans <= (long long)INT_MIN) return INT_MIN;

//         i++;
//     }

//     return isNeg ? -ans : ans;
// }



//recursive
int INT_MAX_ = 2147483647;
    int INT_MIN_ = -2147483648;

    int helper(const string& s, int i, long long ans, int sign) {
        if (i >= s.length() || !isdigit(s[i])) {
            return (int)(sign * ans);
        }

        int digit = s[i] - '0';

        // Clamp before it overflows
        if (ans > (INT_MAX_ - digit) / 10) {
            return (sign == 1) ? INT_MAX_ : INT_MIN_;
        }

        ans = ans * 10 + digit;
        return helper(s, i + 1, ans, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // Skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
int main(){
  
    return 0;
}