from itertools import count
from common import is_prime


def solve():
    c = 0
    Nth_prime = 10_001
    counter = count(start=2)
    while c < Nth_prime:
        num = next(counter)
        if is_prime(num):
            c += 1
    return num

if __name__ == "__main__":
    print(solve())
