import math

from common import collatz_seq
from itertools import count

def solve(upper_limit):
    return max([len(list(collatz_seq(i))) for i in range(1, upper_limit)])

if __name__ == "__main__":
    print(solve(1_000_000))