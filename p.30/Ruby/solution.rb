#!/usr/bin/env ruby
# frozen_string_literal: true


DIGIT_POWERS = (0..9).map{ |d| d**5 }.freeze

def sum_of_fifth_powers_of_digits(num)
  sum = 0
  n = num
  while n > 0
    digit = n % 10
    sum += DIGIT_POWERS[digit]
    n /= 10
  end
  sum
end


def sum_of_fifth_power_numbers
  (2..999_999).select do |n|
    n == sum_of_fifth_powers_of_digits(n)
  end.sum
end

if __FILE__ == $PROGRAM_NAME
  answer = sum_of_fifth_power_numbers
  puts "#{answer}"
end
