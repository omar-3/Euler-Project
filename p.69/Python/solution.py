from typing import List
from math import inf

def prime_factors(n: int) -> List[int]:
    factors = []
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            factors.append(i)
            n = n // i
    # in case n is itself is a prime number
    if n > 1:
        factors.append(n)
    return factors

# n/phi(n)
def totient_function(prime_factors: List[int]) -> float:
    result = 1
    for factor in set(prime_factors):
        result *= (1.0 - 1.0 / factor)
    return 1.0 / result

def main():
    number = None
    max_totient = -inf
    for i in range(2,1000_000):
        totient_value = totient_function(prime_factors(i))
        if totient_value > max_totient:
            max_totient = totient_value
            number = i
    print(number)

if __name__ == "__main__":
    main()
