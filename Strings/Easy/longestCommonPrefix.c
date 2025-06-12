/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/
#include<stdio.h>
#include<stdlib.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    // Manually calculate the length of the first string
    int len = 0;
    while (strs[0][len] != '\0') len++;

    // Allocate memory for the answer (length of first string + 1 for '\0')
    char* ans = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ans[i] = strs[0][i];
    }
    ans[len] = '\0';

    // Compare with the rest of the strings
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (ans[j] != '\0' && strs[i][j] != '\0' && ans[j] == strs[i][j]) {
            j++;
        }
        ans[j] = '\0';  // Truncate at the point of mismatch
        if (j == 0) break;  // No common prefix
    }

    return ans;
}

int main(){

}