def prime_factors(n)
  factors = []
  (2..Math.sqrt(n).to_i).each do |i|
    while (n % i).zero?
      factors << i
      n /= i
    end
  end
  factors << n if n > 1
  factors
end

def totient_function(factors)
  distinct_primes = factors.uniq
  result = 1.0
  distinct_primes.each do |factor|
    result *= (1.0 - 1.0 / factor)
  end
  1.0 / result
end

def main
  max_totient = -Float::INFINITY
  number = 0
  (2..1_000_000).each do |i|
    totient_value = totient_function(prime_factors(i))
    if totient_value > max_totient
      number = i
      max_totient = totient_value
    end
  end
  p number
end

main if __FILE__ == $0
