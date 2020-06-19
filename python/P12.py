from common import num_divisors
from itertools import count


def solve(NUM_DIVS):
    for i in count(1):
        triangle_num = (i*(i+1)) // 2               # the ith triangle number
        num_of_divs = num_divisors(triangle_num)
        if num_of_divs > NUM_DIVS:
            return triangle_num

if __name__ == "__main__":
    print(solve(500))