#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 50000000

int* generate_prime(int limit, int* count) {
  bool* sieve = calloc(limit, sizeof(bool));
  for (int i = 2; i < limit; i++) sieve[i] = true;

  for (int i = 2; i < sqrt(limit); i++) {
    if (sieve[i]) {
      for (int j = i * i; j < limit; j += i) {
        sieve[j] = false;
      }
    }
  }

  *count = 0;
  for (int i = 2; i < limit; i++) {
    if (sieve[i]) (*count)++;
  }

  int *primes = malloc(*count * sizeof(int));
  int index = 0;

  for (int i = 2; i < limit; i++) {
    if (sieve[i]) primes[index++] = i;
  }

  free(sieve);
  return primes;
}

int count_expressible_numbers(int limit) {
  int prime_count;
  int* primes = generate_prime((int)sqrt(limit), &prime_count);

  int *prime_squares = malloc(prime_count * sizeof(int));
  int *prime_cubes = malloc(prime_count * sizeof(int));
  int *prime_fourths = malloc(prime_count * sizeof(int));

  int square_count = 0, cube_count = 0, fourth_count = 0;
  
  for (int i = 0; i < prime_count; i++) {
    int p = primes[i];
    long long square = (long long) p * p;
    long long cube = square * p;
    long long fourth = cube * p;

    if (square < limit) prime_squares[square_count++] = (int)square;
    if (cube < limit) prime_cubes[cube_count++] = (int)cube;
    if (fourth < limit) prime_fourths[fourth_count++] = (int)fourth;
  }

      bool *bitmap = calloc(limit, sizeof(bool));
    int unique_count = 0;

    for (int i = 0; i < square_count; i++) {
        for (int j = 0; j < cube_count; j++) {
            for (int k = 0; k < fourth_count; k++) {
                int total = prime_squares[i] + prime_cubes[j] + prime_fourths[k];
                if (total >= limit) break;

                if (!bitmap[total]) {
                    bitmap[total] = true;
                    unique_count++;
                }
            }
        }
    }

    free(primes);
    free(prime_squares);
    free(prime_cubes);
    free(prime_fourths);
    free(bitmap);

    return unique_count;
}

int main() {
    int result = count_expressible_numbers(LIMIT);
    printf("%d", result);
    return 0;
}
