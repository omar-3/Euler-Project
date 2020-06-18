from common import is_pythagorean

def solve(summation):
    for a in range(1, summation):
        for b in range(a, summation):
            for c in range(b, summation):
                if is_pythagorean(a, b, c) and a + b + c == summation:
                    return (a,b,c), a*b*c


if __name__ == "__main__":
    print(solve(1000))
