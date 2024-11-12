def roman_to_int(roman)
  roman_values = {
    'I' => 1, 'V' => 5, 'X' => 10, 'L' => 50,
    'C' => 100, 'D' => 500, 'M' => 1000
  }
  total = 0
  prev_value = Float::INFINITY

  roman.each_char do |char|
    value = roman_values[char]
    if value > prev_value
      total += value - 2 * prev_value
    else
      total += value
    end
    prev_value = value
  end

  total
end

def int_to_minimal_roman(num)
  mappings = [
    [1000, 'M'], [900, 'CM'], [500, 'D'], [400, 'CD'],
    [100, 'C'], [90, 'XC'], [50, 'L'], [40, 'XL'],
    [10, 'X'], [9, 'IX'], [5, 'V'], [4, 'IV'], [1, 'I']
  ]

  result = ''

  mappings.each do |value, numeral|
    while num >= value
      result += numeral
      num -= value
    end
  end

  result
end


def calculate_savings(filename)
  savings = 0

  File.open(filename).each_line do |line|
    roman = line.strip
    original_length = roman.length
    minimal_length = int_to_minimal_roman(roman_to_int(roman)).length
    savings += original_length - minimal_length
  end

  savings
end

filename = 'roman.txt'
savings = calculate_savings(filename)
puts "Total characters saved: #{savings}"
