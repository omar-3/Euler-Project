UPPER_BOUND = 1_000_000
LOWER_BOUND = 2

def is_sum_of_5th_powers(num: int) -> bool:
    return num == sum(int(digit) ** 5 for digit in str(num))

# I think we can be a bit more smart about the upper bound
def brute_force_it():
    valid_numbers = [
            n for n in range(LOWER_BOUND, UPPER_BOUND)
            if is_sum_of_5th_powers(n)
            ]
    result = sum(valid_numbers)
    return result

if __name__ == "__main__":
    print(brute_force_it())

