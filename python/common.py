import math
from operator import mod
from itertools import repeat, starmap


def is_prime(n):
    return n == 2 or all(starmap(mod, zip( repeat(n), range(2, math.ceil(math.sqrt(n) + 1)))))
