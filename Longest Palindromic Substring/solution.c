#include <stdio.h>
#include <string.h>

#define MAX 1000

void longestPalindrome(char *str) {
    int n = strlen(str);
    int start = 0, maxLength = 1;

    int dp[MAX][MAX] = {0};

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    // Print the result
    // printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLength; i++)
        putchar(str[i]);
    // printf("\n");
}

int main() {
    char str[MAX];
    scanf("%s", str);
    longestPalindrome(str);
    return 0;
}
