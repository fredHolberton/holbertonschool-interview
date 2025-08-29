#!/usr/bin/python3
def isWinner(x, nums):
    """Determine the winner of the prime game"""
    if x < 1 or not nums:
        return None

    n = max(nums)
    # Sieve of Eratosthenes to find primes up to n
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False

    # Precompute prefix sum of primes count
    primes_count = [0] * (n + 1)
    count = 0
    for i in range(n + 1):
        if sieve[i]:
            count += 1
        primes_count[i] = count

    # Simulate the rounds
    maria_wins = 0
    ben_wins = 0
    for num in nums[:x]:
        if primes_count[num] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
