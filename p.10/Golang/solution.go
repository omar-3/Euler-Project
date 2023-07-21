package main

import (
	"fmt"
	"math"
	"math/big"
)

func createPrimeSieve(n int) []bool {
	sieve := make([]bool, n+1)

	for i := 2; i <= n; i++ {
		sieve[i] = true
	}

	limit := int(math.Sqrt(float64(n)))

	for i := 2; i <= limit; i++ {
		if !sieve[i] {
			continue
		}

		for j := i * i; j <= n; j += i {
			sieve[j] = false
		}
	}

	return sieve
}

func calculatePrimeSum(sieve []bool) *big.Int {
	sum := big.NewInt(0)
	for i, isPrime := range sieve {
		if isPrime {
			sum.Add(sum, big.NewInt(int64(i)))
		}
	}
	return sum
}

func main() {
	n := 2000000
	sieve := createPrimeSieve(n)
	fmt.Printf("Sum of all primes up to %d: %s\n", n, calculatePrimeSum(sieve).String())
}
