#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int *prime_factors(int n, int *size) {
  int *factors = (int *)malloc(n * sizeof(int));
  *size = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    while (n % i == 0) {
      factors[(*size)++] = i;
      n = n / i;
    }
  }
  if (n > 1) {
    factors[(*size)++] = n;
  }
  factors = (int *)realloc(factors, sizeof(int) * (*size));
  return factors;
}

double totient_function(int *factors, int size) {
  double phi = 1.0;
  for (int i = 0; i < size; i++) {
    int p = factors[i];
    if (i > 0 && p == factors[i - 1])
      continue;
    phi *= (1.0 - (1.0 / p));
  }
  return 1.0 / phi;
}

int main() {
  double max_totient = -1.0;
  int number = 0;
  for (int i = 2; i <= 1000000; i++) {
    int size;
    int *factors = prime_factors(i, &size);
    double totient_value = totient_function(factors, size);
    if (totient_value > max_totient) {
      number = i;
      max_totient = totient_value;
    }
  }
  fprintf(stdout, "%d\n", number);
  return 0;
}
