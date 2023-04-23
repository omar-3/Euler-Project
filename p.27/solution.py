import itertools
import math

NO_OF_DIGITS = 1000

def no_of_digits(number):
    return int(math.log10(number)) + 1

def solve(N):
    prev = 0
    cur = 1
    for i in itertools.count():
        if no_of_digits(cur) == N:
            return i
        prev, cur = cur, cur + prev

print(solve(NO_OF_DIGITS))
