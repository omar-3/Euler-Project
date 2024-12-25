package main

import (
  "fmt"
  "math"
)

func GeneratePrimes(limit int) []int {
  sieve := make([]bool, limit)
  for i := range sieve {
    sieve[i] = true
  }
  sieve[0], sieve[1] = false, false

  for i := 2; i <= int(math.Sqrt(float64(limit))); i++ {
    if sieve[i] {
      for j := i * i; j <= limit; j += i {
        sieve[j] = false
      }
    }
  }


  var primes []int

  for i, isPrime := range sieve {
    if isPrime {
      primes = append(primes, i)
    }
  }

  return primes
}
