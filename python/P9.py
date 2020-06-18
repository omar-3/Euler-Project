from common import is_pythagorean

def solve(total):
    for a in range(1, total):
        for b in range(a, total):
            for c in range(b, total):
                if is_pythagorean(a, b, c) and a + b + c == total:
                    return (a,b,c), a*b*c


if __name__ == "__main__":
    print(solve(1000))
