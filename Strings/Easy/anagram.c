/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.*/

#include <stdio.h>
#include <stdbool.h>
// Check if t is an anagram of s
bool isAnagram(char* s, char* t) {
    int freq[26] = {0};

    int i = 0;
    while (s[i] != '\0') {
        freq[s[i] - 'a']++;
        i++;
    }

    i = 0;
    while (t[i] != '\0') {
        freq[t[i] - 'a']--;
        i++;
    }

    // If any frequency is non-zero, not an anagram
    for (int j = 0; j < 26; j++) {
        if (freq[j] != 0)
            return false;
    }
    return true;
}

int main() {
    char s[100], t[100];
    scanf("%s", s);
    scanf("%s", t);

    if (isAnagram(s, t))
        printf("Yes, anagrams of each other\n");
    else
        printf("No, not anagrams\n");

    return 0;
}
