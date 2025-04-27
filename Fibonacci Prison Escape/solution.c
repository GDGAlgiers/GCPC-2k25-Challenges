#include <stdio.h>
#include <limits.h>

#define MAX_N 1000

// Function to generate Fibonacci numbers up to N
void generate_fibonacci(int fib[], int *fib_count, int N) {
    int a = 1, b = 2, i = 0;
    fib[i++] = a;
    fib[i++] = b;
    
    while (b <= N) {
        int next_fib = a + b;
        if (next_fib > N) break;
        fib[i++] = next_fib;
        a = b;
        b = next_fib;
    }
    *fib_count = i;
}

// Function to find the minimum jumps to escape
int min_jumps_to_escape(int N, int doors[]) {
    int fib[MAX_N], fib_count;
    
    // Generate Fibonacci numbers up to N
    generate_fibonacci(fib, &fib_count, N);
    
    // dp[i] will store the minimum number of jumps to reach door i
    int dp[MAX_N];
    
    // Initialize dp array with infinity
    for (int i = 0; i < N; i++) {
        dp[i] = INT_MAX;
    }
    
    // Starting point, no jumps required to reach the first door
    dp[0] = doors[0] == 1 ? 0 : INT_MAX;
    
    // Iterate over each door to compute the minimum jumps
    for (int i = 1; i < N; i++) {
        if (doors[i] == 0) continue; // If the door is broken, skip it
        
        for (int j = 0; j < fib_count; j++) {
            int jump = fib[j];
            if (i - jump >= 0 && doors[i - jump] == 1 && dp[i - jump] != INT_MAX) {
                if (dp[i] > dp[i - jump] + 1) {
                    dp[i] = dp[i - jump] + 1;
                }
            }
        }
    }
    
    // If dp[N-1] is still infinity, it means the last door is unreachable
    return dp[N-1] == INT_MAX ? -1 : dp[N-1];
}

int main() {
    int N;
    
    scanf("%d", &N);

    if (N > MAX_N || N <= 0) {
        return 1;
    }

    int doors[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &doors[i]);
    }
    
    int result = min_jumps_to_escape(N, doors);
    
    if (result == -1) {
        printf("-1");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
