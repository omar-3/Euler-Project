#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> prime_sive(int n) {
  std::vector<bool> sieve(n + 1, true);
  sieve[0] = false;
  sieve[1] = false;

  for (int elem = 2; elem <= std::sqrt(n); elem++) {
    if (sieve[elem]) {
      for (int multiple = elem * elem; multiple <= n; multiple += elem) {
        sieve[multiple] = false;
      }
    }
  }

  std::vector<int> primes;
  for (int i = 1; i <= n; i++) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  auto primes = prime_sive(2000000);
  auto total = std::accumulate(primes.begin(), primes.end(), 0LL);

  std::cout << total << std::endl;
  return 0;
}
