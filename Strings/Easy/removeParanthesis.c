#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.*/
char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char* ans = malloc(n + 1); // Allocate memory for the result
    if (ans == NULL) return NULL;

    int count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (count > 0) {
                ans[j++] = s[i];  // Only include if it's not the outermost '('
            }
            count++;
        } else if (s[i] == ')') {
            count--;
            if (count > 0) {
                ans[j++] = s[i];  // Only include if it's not the outermost ')'
            }
        }
    }

    ans[j] = '\0'; // Null-terminate the string
    return ans;
}
//function that doesn't allocate extra space in start or use strlen() but reallocates memory each time by starting from small 16
char* removeOuterParenthesesRealloc(char* s) {
    char* ans = NULL;  // Result string
    int capacity = 0;  // Allocated size
    int j = 0;         // Index to write into ans
    int count = 0;     // Nesting level

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            if (count > 0) {
                // Need to store this char
                if (j >= capacity) {
                    capacity = capacity == 0 ? 16 : capacity * 2;
                    ans = realloc(ans, capacity);
                    if (ans == NULL) return NULL;
                }
                ans[j++] = s[i];
            }
            count++;
        } else if (s[i] == ')') {
            count--;
            if (count > 0) {
                if (j >= capacity) {
                    capacity = capacity == 0 ? 16 : capacity * 2;
                    ans = realloc(ans, capacity);
                    if (ans == NULL) return NULL;
                }
                ans[j++] = s[i];
            }
        }
    }

    // Final null terminator
    if (j >= capacity) {
        ans = realloc(ans, j + 1);
        if (ans == NULL) return NULL;
    }
    ans[j] = '\0';
    return ans;
}
int main(){
    return 0;
}