def LinearMemoryReprogramming(s: str) -> int:
        n = len(s)
        if not s:
            return 0

        dp = [[0] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            dp[i][i] = 1  
            for j in range(i + 1, n):
                dp[i][j] = dp[i + 1][j] + 1  

                for k in range(i + 1, j + 1):
                    if s[i] == s[k]:
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j])

        return dp[0][n - 1]
if __name__ == "__main__":
    s = input().strip()  # Read a line and remove spaces/newlines
    print(LinearMemoryReprogramming(s))
