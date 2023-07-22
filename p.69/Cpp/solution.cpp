#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

// Function to calculate prime factors
std::vector<int> prime_factors(int n) {
  std::vector<int> factors;
  for (int i = 2; i <= std::sqrt(n); i++) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    factors.push_back(n);
  }
  return factors;
}

// Function to calculate n/phi n
double totient_function(const std::vector<int> &&prime_factors) {
  double result = 1.0;
  std::unordered_set<int> distinct_primes(prime_factors.begin(),
                                          prime_factors.end());

  for (int factor : distinct_primes) {
    result *= (1.0 - 1.0 / factor);
  }

  return 1.0 / result;
}

int main() {
  int number = 0;
  double max_totient = -INFINITY;
  for (int i = 2; i <= 1000000; i++) {
    double totient_value = totient_function(prime_factors(i));
    if (totient_value > max_totient) {
      max_totient = totient_value;
      number = i;
    }
  }
  std::cout << number << std::endl;
  return 0;
}
