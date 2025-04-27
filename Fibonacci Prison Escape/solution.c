#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compress the string
char* compress(const char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(2 * len + 1); // Worst case: "a1b1c1..."
    int i = 0, pos = 0;

    while (i < len) {
        char current = s[i];
        int count = 1;
        while (i + 1 < len && s[i] == s[i + 1]) {
            i++;
            count++;
        }
        result[pos++] = current;
        if (count > 1) {
            pos += sprintf(result + pos, "%d", count);
        }
        i++;
    }

    result[pos] = '\0';
    return result;
}

// Function to decompress the string
char* decompress(const char* t) {
    int len = strlen(t);
    char* result = (char*)malloc(100000 * sizeof(char)); // Maximum input length
    int pos = 0;

    for (int i = 0; i < len; i++) {
        char current = t[i];
        int count = 0;

        // Check if the next characters are digits
        while (i + 1 < len && isdigit(t[i + 1])) {
            count = count * 10 + (t[i + 1] - '0');
            i++;
        }

        if (count == 0) count = 1;
        for (int j = 0; j < count; j++) {
            result[pos++] = current;
        }
    }

    result[pos] = '\0';
    return result;
}

// Main function to test examples
int main() {
  
    char s[1000];
        scanf("%s",&s);
        char* compressed = compress(s);
        printf("%s", compressed);
        free(compressed);


    return 0;
}
