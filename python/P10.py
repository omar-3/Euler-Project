from common import is_prime

def solve(upper_limit):
    summation = 0
    for i in range(2,upper_limit):
        if is_prime(i):
            summation += i
    return summation

if __name__ == "__main__":
    print(solve(2_000_000))