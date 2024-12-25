#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

std::vector<int> generate_primes(int limit) {
    std::vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= std::sqrt(limit); ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (sieve[i]) primes.push_back(i);
    }
    return primes;
}

int count_expressible_numbers(int limit) {
    auto primes = generate_primes(static_cast<int>(std::sqrt(limit)));

    std::vector<int> prime_squares, prime_cubes, prime_fourths;

    for (const auto& p : primes) {
        long long square = static_cast<long long>(p) * p;
        long long cube = square * p;
        long long fourth = cube * p;

        if (square < limit) prime_squares.push_back(square);
        if (cube < limit) prime_cubes.push_back(cube);
        if (fourth < limit) prime_fourths.push_back(fourth);
    }

    std::unordered_set<int> expressible_numbers;

    for (const auto& square : prime_squares) {
        for (const auto& cube : prime_cubes) {
            if (square + cube >= limit) break;
            for (const auto& fourth : prime_fourths) {
                int total = square + cube + fourth;
                if (total >= limit) break;
                expressible_numbers.insert(total);
            }
        }
    }

    return expressible_numbers.size();
}

int main() {
    int limit = 50'000'000; 
    int result = count_expressible_numbers(limit);
    std::cout << limit << ": " << result ;
    return 0;
}

