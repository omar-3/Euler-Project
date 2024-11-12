#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>

int roman_to_int(const std::string& roman) {
  const std::unordered_map<char, int> roman_values = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
  };
  int total = 0;
  int prev_value = std::numeric_limits<int>::max();

  for (char c : roman) {
    int value = roman_values.at(c);
    if (value > prev_value) {
      total += value - 2 * prev_value;
    } else {
      total += value;
    }
    prev_value = value;
  }
  return total;
}


std::string int_to_minimal_roman(int num) {
  const std::vector<std::pair<int, std::string>> mappings = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
  };
  std::string result;

  for (const auto& [value, numeral] : mappings) {
    while (num >= value) {
      result += numeral;
      num -= value;
    }
  }

  return result;
}

int calculate_savings(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  int savings = 0;
  std::string line;
  while (std::getline(file, line)) {
    int original_length = line.size();
    int minimal_length = int_to_minimal_roman(roman_to_int(line)).size();
    savings += original_length - minimal_length;
  }

  return savings;
}

int main() {
  const std::string filename = "roman.txt";
  try {
    int savings = calculate_savings(filename);
    std::cout << "Total characters saved: " << savings << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
