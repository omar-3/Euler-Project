def count_partitions(n: int) -> int:
    dp = [1] + [0] * n
    for i in range(1, n+1):
        for j in range(i, n+1):
            dp[j] += dp[j - i]
    return dp[n]

print(count_partitions(100) - 1) # the minus one because we need more than two summands
