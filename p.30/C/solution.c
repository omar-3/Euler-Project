#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define UPPER_BOUND 999999

static const int digit_powers[10] = {
    0,      // 0^5
    1,      // 1^5
    32,     // 2^5
    243,    // 3^5
    1024,   // 4^5
    3125,   // 5^5
    7776,   // 6^5
    16807,  // 7^5
    32768,  // 8^5
    59049   // 9^5
};

static inline int sum_of_5th_powers_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit_powers[digit];
        n /= 10;
    }
    return sum;
}

static inline bool is_sum_of_5th_powers(int n) {
    return n == sum_of_5th_powers_of_digits(n);
}

int main(void) {
    uint64_t total_sum = 0;

    for (int i = 2; i <= UPPER_BOUND; i++) {
        if (is_sum_of_5th_powers(i)) {
            total_sum += i;
        }
    }

    fprintf(stdout, "%d", total_sum);
    return 0;
}
