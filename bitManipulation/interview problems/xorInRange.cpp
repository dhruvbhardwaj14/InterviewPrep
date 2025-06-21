#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].*/
/*Approach- 

XOR from 0 to n:
- n % 4 == 0 → result = n
- n % 4 == 1 → result = 1
- n % 4 == 2 → result = n + 1
- n % 4 == 3 → result = 0

XOR(L to R) = XOR(0 to R) ^ XOR(0 to L-1)

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).
*/
int xorUpto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int findXOR(int l, int r) {
    return xorUpto(r) ^ xorUpto(l - 1);
}

int main(){
  
    return 0;
}
// 4- 100
// 5- 101
// 6- 110
// 7- 111