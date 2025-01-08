#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

// this gives wrong answer for some reason, ughhhhhh

std::vector<int> digits_of(std::uint64_t num) {
    if (num == 0) {
        return {0};
    }

    std::vector<int> digits;
    digits.reserve(20);

    while (num > 0) {
        int d = static_cast<int>(num % 10);
        digits.push_back(d);
        num /= 10;
    }

    std::reverse(digits.begin(), digits.end());
    return digits;
}

bool is_increasing(std::uint64_t num) {
    auto digs = digits_of(num);
    return std::is_sorted(digs.begin(), digs.end(), std::less_equal<int>());
}

bool is_decreasing(std::uint64_t num) {
    auto digs = digits_of(num);
    return std::is_sorted(digs.begin(), digs.end(), std::greater_equal<int>());
}

bool is_bouncy(std::uint64_t num) {
    return !(is_increasing(num) || is_decreasing(num));
}

int main() {
    std::uint64_t n = 99;
    std::uint64_t bouncy_count = 0;

    while (true) {
        ++n;
        if (is_bouncy(n)) {
            ++bouncy_count;
        }

        if (bouncy_count * 100 == 99ULL * n) {
            std::cout << n << std::endl;
            break;
        }
    }
    return 0;
}
