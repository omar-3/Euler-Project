import math
from operator import mod
from itertools import repeat, starmap


def is_prime(n):
    return n == 2 or all(starmap(mod, zip( repeat(n), range(2, math.ceil(math.sqrt(n) + 1)))))


def is_pythagorean(a, b, c):
    if a**2 + b**2 == c**2:
        return True
    return False


def num_divisors(n):
    count = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0: count += 2
        if i * i == n: count -= 1   # perfect squares
    return count

def next_collatz_elem(n):
    if n & 1: return 3*n + 1
    else: return n // 2

def collatz_seq(n):
    element = n
    while element != 1:
        element =  next_collatz_elem(element)
        yield element