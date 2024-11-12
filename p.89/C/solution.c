#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE_LENGTH 100

int roman_to_int(const char *roman) {
  int values[26] = {0};
  values['I' - 'A'] = 1;
  values['V' - 'A'] = 5;
  values['X' - 'A'] = 10;
  values['L' - 'A'] = 50;
  values['C' - 'A'] = 100;
  values['D' - 'A'] = 500;
  values['M' - 'A'] = 1000;

  int total = 0;
  int prev_value = INT_MAX;

  for (int i = 0; roman[i] != '\0'; i++) {
    int value = values[roman[i] - 'A'];
    if (value > prev_value) {
      total += value - 2 * prev_value;
    } else {
      total += value;
    }
    prev_value = value;
  }

  return total;
}

void int_to_minimal_roman(int num, char* result) {
  struct {
    int value;
    const char* numeral;
  } mappings[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
  };

  result[0] = '\0';

  for (int i = 0; i < sizeof(mappings) / sizeof(mappings[0]); i++) {
    while (num >= mappings[i].value) {
      strcat(result, mappings[i].numeral);
      num -= mappings[i].value;
    }
  }
}

int calculate_savings(const char* filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Could not open file");
    return -1;
  }

  int savings = 0;
  char line[MAX_LINE_LENGTH];
  char minimal_form[MAX_LINE_LENGTH];

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = '\0';

    int original_length = strlen(line);
    int minimal_value = roman_to_int(line);
    int_to_minimal_roman(minimal_value, minimal_form);
    int minimal_length = strlen(minimal_form);

    savings += original_length - minimal_length;
  }

  fclose(file);
  return savings;
}

int main() {
  const char* filename = "roman.txt";
  int savings = calculate_savings(filename);
  if (savings >= 0) {
    printf("Total characters saved: %d\n", savings);
  }
  return 0;
}
