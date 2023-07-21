#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool *create_prime_sieve(uint64_t n) {
  bool *sieve = (bool *)calloc(n + 1, sizeof(bool));
  memset(sieve, true, (n + 1) * sizeof(bool));
  sieve[0] = sieve[1] = false;

  uint64_t limit = (uint64_t)sqrt(n);
  for (uint64_t elem = 2; elem <= limit; elem++) {
    if (!sieve[elem]) {
      continue;
    }

    for (uint64_t multiple = elem * elem; multiple <= n; multiple += elem) {
      sieve[multiple] = false;
    }
  }

  return sieve;
}

uint64_t calculate_prime_sum(bool *sieve, uint64_t n) {
  uint64_t sum = 0;
  for (uint64_t i = 0; i <= n; i++) {
    if (sieve[i]) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  uint64_t n = 2000000;
  bool *sieve = create_prime_sieve(n);
  fprintf(stdout, "Sum of all primes up to %ju: %ju\n", n,
          calculate_prime_sum(sieve, n));
  free(sieve);
}
