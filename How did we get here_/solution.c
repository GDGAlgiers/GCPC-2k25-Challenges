// Efficient modular exponentiation using binary exponentiation (square-and-multiply method)
// Time complexity: O(log b)
// Space complexity: O(1)
int moduloPower(int a, int b, int modulo)
{
    // Initialize result to 1 (multiplicative identity)
    int result = 1;

    // Reduce base to its equivalent within modulo range
    a %= modulo;

    // Binary exponentiation algorithm
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

// Depth-first search to generate all subsets and compute their Power Modulo Sum
// Time complexity: O(2^n), where n is the number of elements
// Space complexity: O(n) due to recursive call stack
int dfs(int *nums, int numsSize, int cuurPowerModuloSum, int length)
{
    // Base case: when no more elements to process
    // Return the current Power Modulo Sum modulo (length + 1)
    if (numsSize == 0)
    {
        return cuurPowerModuloSum % (length + 1);
    }

    // Recursive exploration of all subset combinations:
    // 1. Exclude current element (left subtree)
    // 2. Include current element by computing its power modulo sum (right subtree)
    return dfs(nums + 1, numsSize - 1, cuurPowerModuloSum, length) +
           dfs(nums + 1, numsSize - 1, cuurPowerModuloSum + moduloPower(nums[0], nums[0], length + 2), length + 1);
}

// Main function to compute the sum of Power Modulo Sums for all subsets
int subsetPowerModuloSumsSum(int *nums, int numsSize)
{
    return dfs(nums, numsSize, 0, 0);
}