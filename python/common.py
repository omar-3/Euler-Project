import math
from operator import mod
from itertools import repeat, starmap


def is_prime(n):
    return n == 2 or all(starmap(mod, zip( repeat(n), range(2, math.ceil(math.sqrt(n) + 1)))))


def is_pythagorean(a, b, c):
    if a**2 + b**2 == c**2:
        return True
    return False