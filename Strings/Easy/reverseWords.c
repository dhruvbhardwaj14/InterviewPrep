/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int i = 0;
    int wordCount = 0;
    int capacity = 8;

    char** words = (char**)malloc(sizeof(char*) * capacity);
    int* lengths = (int*)malloc(sizeof(int) * capacity);

    // Skip initial spaces
    while (s[i] == ' ') i++;

    while (s[i] != '\0') {
        // Start of word
        char* wordStart = &s[i];
        int len = 0;

        // Copy until space or end
        while (s[i] != '\0' && s[i] != ' ') {
            len++;
            i++;
        }

        // Save word pointer and length
        if (wordCount >= capacity) {
            capacity *= 2;
            words = (char**)realloc(words, sizeof(char*) * capacity);
            lengths = (int*)realloc(lengths, sizeof(int) * capacity);
        }

        words[wordCount] = wordStart;
        lengths[wordCount] = len;
        wordCount++;

        // Skip extra spaces between words
        while (s[i] == ' ') i++;
    }

    // Build the reversed output string
    int totalLength = 0;
    for (int j = 0; j < wordCount; j++) {
        totalLength += lengths[j];
    }
    totalLength += wordCount - 1; // for spaces

    char* result = (char*)malloc(totalLength + 1); // +1 for null terminator
    int pos = 0;

    for (int j = wordCount - 1; j >= 0; j--) {
        for (int k = 0; k < lengths[j]; k++) {
            result[pos++] = words[j][k];
        }
        if (j > 0) {
            result[pos++] = ' ';
        }
    }
    result[pos] = '\0';

    free(words);
    free(lengths);
    return result;
}

int main(){
    return 0;
}