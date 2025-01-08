#include <iostream>
#include <array>
#include <cstdint>

static constexpr int UPPER_BOUND = 999999;

static constexpr std::array<int, 10> DIGIT_POWERS = []{
    std::array<int, 10> arr{};
    for (int d = 0; d < 10; ++d) {
        int prod = 1;
        for (int i = 0; i < 5; i++) {
            prod *= d;
        }
        arr[d] = prod;
    }
    return arr;
}();


inline int sumOfFifthPowersOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        const int digit = n % 10;
        sum += DIGIT_POWERS[digit];
        n /= 10;
    }
    return sum;
}

inline bool isSumOfFifthPowers(int n) {
    return n == sumOfFifthPowersOfDigits(n);
}

int main() {
    std::uint64_t totalSum = 0;

    for (int i = 2; i <= UPPER_BOUND; i++) {
        if (isSumOfFifthPowers(i)) {
            totalSum += i;
        }
    }

    std::cout << totalSum << std::endl;
    return 0;
}
