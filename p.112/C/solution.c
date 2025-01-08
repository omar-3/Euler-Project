#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int get_digits(uint64_t num, int digits[]) {
    int count = 0;

    if (num == 0) {
        digits[0] = 0;
        return 1;
    }

    int temp[20];
    while (num > 0) {
        temp[count++] = (int)(num % 10);
        num /= 10;
    }

    for (int i = 0; i < count; i++) {
        digits[i] = temp[count - 1 - i];
    }

    return count;
}

bool is_decreasing(uint64_t num) {
    int digits[20];
    int count = get_digits(num, digits);
    for (int i = 0; i < count - 1; i++) {
        if (digits[i] < digits[i+1]) return false;
    }
    return true;
}

bool is_increasing(uint64_t num) {
    int digits[20];
    int count = get_digits(num, digits);
    for (int i = 0; i < count - 1; i++) {
        if (digits[i] > digits[i+1]) return false;
    }
    return true;
}

bool is_bouncy(uint64_t num) {
    return !(is_increasing(num) || is_decreasing(num));
}

int main(void) {
    uint64_t n = 99;
    uint64_t bouncy_count = 0;

    while (1) {
        n++;
        if (is_bouncy(n)) {
            bouncy_count++;
        }

        if (bouncy_count * 100 == 99ULL * n) {
            printf("%llu", (long long unsigned) n);
            break;
        }
    }

    return 0;
}
