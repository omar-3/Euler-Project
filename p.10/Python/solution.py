from typing import List

def prime_sieve(n: int) -> List[int]:
    sieve = [True] * (n + 1)
    for elem in range(2, int(n ** 0.5) + 1):
        if sieve[elem]:
            for multiple in range(elem * elem, n + 1, elem):
                sieve[multiple] = False
    return [elem for elem in range(2, n) if sieve[elem]]

def main():
    print(sum(prime_sieve(2000_000)))

if __name__ == "__main__":
    main()


