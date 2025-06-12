#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(const char *input) {
    // Step 1: Find the length of the input string
    int len = strlen(input);

    // Step 2: Allocate memory for the reversed string (+1 for '\0')
    char *reversed = malloc(len + 1);
    if (reversed == NULL) {
        // Allocation failed
        return NULL;
    }

    // Step 3: Copy characters in reverse order
    for (int i = 0; i < len; ++i) {
        reversed[i] = input[len - 1 - i];
    }

    // Step 4: Null-terminate the reversed string
    reversed[len] = '\0';

    // Step 5: Return the pointer
    return reversed;
}

int main() {
    const char *original = "C Programming";
    char *reversed = reverse_string(original);

    if (reversed != NULL) {
        printf("Original: %s\n", original);
        printf("Reversed: %s\n", reversed);
        free(reversed);  // Always free dynamically allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
