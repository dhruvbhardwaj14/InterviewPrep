/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// // Custom strlen function
// int my_strlen(char* str) {
//     int len = 0;
//     while (str[len] != '\0') len++;
//     return len;
// }

// // Function to check if s rotated by 'shift' positions equals goal
// bool isRotationMatch(char* s, char* goal, int len, int shift) {
//     for (int i = 0; i < len; i++) {
//         if (s[(i + shift) % len] != goal[i]) {
//             return false;
//         }
//     }
//     return true;
// }

// // Main function to check if s can be rotated to become goal
// bool rotateString(char* s, char* goal) {
//     int lenS = my_strlen(s);
//     int lenG = my_strlen(goal);
    
//     if (lenS != lenG) return false;

//     for (int shift = 0; shift < lenS; shift++) {
//         if (isRotationMatch(s, goal, lenS, shift)) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     char* s = malloc(sizeof(char) * 101);
//     char* t = malloc(sizeof(char) * 101);

//     scanf("%s", s);
//     scanf("%s", t);

//     if (rotateString(s, t))
//         printf("Yes, rotated of each other\n");
//     else
//         printf("No, Not rotated of each other\n");

//     free(s);
//     free(t);
//     return 0;
// }


// O(N) using KMP string matching Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Custom strlen
int my_strlen(char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Build LPS (Longest Prefix Suffix) array for KMP
void computeLPS(char* pattern, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
}

// KMP string match: checks if pattern exists in text
bool KMP(char* text, int n, char* pattern, int m) {
    int* lps = malloc(sizeof(int) * m);
    computeLPS(pattern, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                free(lps);
                return true;
            }
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    free(lps);
    return false;
}

// Main function to check if goal is a rotation of s
bool rotateString(char* s, char* goal) {
    int n = my_strlen(s);
    int m = my_strlen(goal);

    if (n != m) return false;

    // Build s + s manually (simulate it)
    char* text = malloc(sizeof(char) * (2 * n + 1));
    for (int i = 0; i < n; i++) {
        text[i] = s[i];
        text[n + i] = s[i];
    }
    text[2 * n] = '\0';

    return KMP(text, 2 * n, goal, n);
}

int main() {
    char* s = malloc(sizeof(char) * 101);
    char* t = malloc(sizeof(char) * 101);

    scanf("%s", s);
    scanf("%s", t);

    if (rotateString(s, t))
        printf("Yes, rotated of each other\n");
    else
        printf("No, Not rotated of each other\n");

    free(s);
    free(t);
    return 0;
}
