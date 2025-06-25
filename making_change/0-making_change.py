#!/usr/bin/python3
"""A module to determine the fewest number of coins to meet a given amount"""


def makeChange(coins, total):
    """Return the fewest number of coins needed to meet total"""
    if total <= 0:
        return 0

    # Initialize DP array with total+1 (a value greater than possible coin count)
    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amt in range(1, total + 1):
        for coin in coins:
            if coin <= amt:
                dp[amt] = min(dp[amt], dp[amt - coin] + 1)

    return dp[total] if dp[total] != total + 1 else -1
