// This code generated wrong answer - help me fix it if you catch the erro
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100
#define MAX_SUM 338350 // = 1^2 + 2^2 + 3^2 + ... + 100^2
#define SUBSET_SIZE 50

int main() {
  int square_numbers[MAX_NUM];
  for (int i = 1; i <= MAX_NUM; i++) {
    square_numbers[i - 1] = i * i;
  }

  bool *seen_sums[SUBSET_SIZE + 1];
  bool *unique_sums[SUBSET_SIZE + 1];
  for (int i = 0; i <= SUBSET_SIZE; i++) {
    seen_sums[i] = calloc(MAX_SUM + 1, sizeof(bool));
    unique_sums[i] = calloc(MAX_SUM + 1, sizeof(bool));
  }
  seen_sums[0][0] = true;
  unique_sums[0][0] = true;

  for (int num = 0; num < MAX_NUM; num++) {
    int square = square_numbers[num];
    for (int count = SUBSET_SIZE - 1; count >= 0; count--) {
      for (int sum = 0; sum + square <= MAX_SUM; sum++) {
        if (seen_sums[count][sum]) {
          int new_sum = sum + square;
          if (!seen_sums[count + 1][new_sum] && unique_sums[count][sum]) {
            seen_sums[count + 1][new_sum] = true;
            unique_sums[count + 1][new_sum] = true;
          } else {
            unique_sums[count + 1][new_sum] = false;
          }
        }
      }
    }
  }

  long unique_sum_total = 0;
  for (int sum = 1; sum <= MAX_SUM; sum++) {
    if (unique_sums[SUBSET_SIZE][sum]) {
      unique_sum_total += sum;
    }
  }

  printf("Unique sum total: %ld\n", unique_sum_total);

  // Free allocated memory
  for (int i = 0; i <= SUBSET_SIZE; i++) {
    free(seen_sums[i]);
    free(unique_sums[i]);
  }
  return 0;
}
