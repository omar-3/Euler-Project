def prime_sieve(n)
  sieve = Array.new(n + 1, true)
  sieve[0] = sieve[1] = false
  limit = Math.sqrt(n).to_i

  (2..limit).each do |elem|
    next unless sieve[elem]

    (elem * elem..n).step(elem) do |multiple|
      sieve[multiple] = false
    end
  end

  sieve.each_index.select { |i| sieve[i] }
end

def main
  primes = prime_sieve(2_000_000)
  p primes.sum
end

main if __FILE__ == $0
