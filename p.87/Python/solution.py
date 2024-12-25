from math import isqrt

def generate_primes(n):
    sieve = [True] * n
    sieve[0] = sieve[1] = False
    for i in range(2, isqrt(n) + 1):
        if sieve[i]:
            for j in range(i * i, n, i):
                sieve[j] = False
    return [x for x in range(n) if sieve[x]]

def count_expressible_numbers(limit):
    primes = generate_primes(limit)

    primes_squares = [p**2 for p in primes if p**2 < limit]
    primes_cubes = [p**3 for p in primes if p**3 < limit]
    primes_fourth = [p**4 for p in primes if p**4 < limit]

    expressible_numbers = set()

    for square in primes_squares:
        for cube in primes_cubes:
            for fourth in primes_fourth:
                total = square + cube + fourth
                if total < limit:
                    expressible_numbers.add(total)

    return len(expressible_numbers)


limit = 50_000_000
print(count_expressible_numbers(limit))
