package main

import (
  "bufio"
  "fmt"
  "os"
  "strings"
)

func romanToInt(roman string) int {
  romanValues := map[rune]int {
    'I': 1, 'V': 5, 'X': 10, 'L': 50,
    'C': 100, 'D': 500, 'M': 1000,
  }

  total := 0
  prevValue := int(^uint(0) >> 1)

  for _, c := range roman {
    value := romanValues[c]
    if value > prevValue {
      total += value - 2 * prevValue
    } else {
      total += value
    }
    prevValue = value
  }

  return total
}

func intToMinimalRoman(num int) string {
  mappings := []struct {
    value int
    numeral string
  }{
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
  }

  var result strings.Builder
  for _, m := range mappings {
    for num >= m.value {
      result.WriteString(m.numeral)
      num -= m.value
    }
  }
  return result.String()
}

func calculateSavings(filename string) (int, error) {
  file, err := os.Open(filename)
  if err != nil {
    return 0, err
  }
  defer file.Close()

  savings := 0
  scanner := bufio.NewScanner(file)

  for scanner.Scan() {
    roman := scanner.Text()
    originalLength := len(roman)
    minimalLength := len(intToMinimalRoman(romanToInt(roman)))
    savings += originalLength - minimalLength
  }

  if err := scanner.Err(); err != nil {
    return 0, err
  }

  return savings, nil
}

func main() {
  filename := "roman.txt"
  savings, err := calculateSavings(filename)
  if err != nil {
    fmt.Fprintf(os.Stderr, "Error: %v\n", err)
    os.Exit(1)
  }
  fmt.Printf("Total characters saved: %d\n", savings)
}
