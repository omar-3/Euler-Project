def solve():
    N = 100
    num_sequence = range(1, N + 1)
    sum_of_squares = sum(i**2 for i in num_sequence)
    sum_squared = sum(i for i in num_sequence) ** 2
    return sum_squared - sum_of_squares 

if __name__ == "__main__":
    print(solve())
