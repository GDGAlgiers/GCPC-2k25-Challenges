#include <stdio.h>
#include <stdlib.h>

int moduloPower(int a, int b, int modulo)
{
    // Reduce base to its equivalent within modulo range
    a %= modulo;

    // Binary exponentiation algorithm (square-and-multiply)
    int result = 1;
    while (b > 0)
    {
        // If current bit is 1, multiply result by current power of a
        if (b & 1)
            result = (result * a) % modulo;

        // Square the base for next iteration
        a = (a * a) % modulo;

        // Right shift to process next bit
        b >>= 1;
    }
    return result;
}

int dfs(int *nums, int numsSize, int currentPowerModuloSum, int length)
{
    // Base case: when no more elements to process
    if (numsSize == 0)
    {
        return currentPowerModuloSum % (length + 1);
    }

    // Recursive exploration of all subset combinations:
    // 1. Exclude current element (left subtree)
    // 2. Include current element by computing its power modulo sum (right subtree)
    return dfs(nums + 1, numsSize - 1, currentPowerModuloSum, length) +
           dfs(nums + 1, numsSize - 1, currentPowerModuloSum + moduloPower(nums[0], nums[0], length + 2), length + 1);
}

// Main function to compute the sum of Power Modulo Sums for all subsets
int subsetPowerModuloSumsSum(int *nums, int numsSize)
{
    return dfs(nums, numsSize, 0, 0);
}

int main()
{
    int nums[20];
    int numsSize = 0;
    int input;

    // Read the input from the terminal until EOF
    while (scanf("%d", &input) != EOF)
    {
        nums[numsSize++] = input;
    }

    // Calculate the sum of Power Modulo Sums for all subsets
    int result = subsetPowerModuloSumsSum(nums, numsSize);

    // Print the result without extra messages
    printf("%d\n", result);

    return 0;
}
