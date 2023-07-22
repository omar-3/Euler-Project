package main

import (
	"fmt"
	"math"
)

func primeFactors(n int) []int {
	factors := make([]int, 0)
	for i := 2; i <= int(math.Sqrt(float64(n))); i++ {
		for n%i == 0 {
			n /= i
			if len(factors) == 0 || factors[len(factors)-1] != i {
				factors = append(factors, i)
			}
		}
	}
	if n > 1 {
		factors = append(factors, n)
	}
	return factors
}

func totient(n int) float64 {
	result := 1.0
	for _, p := range primeFactors(n) {
		result += 1 - 1/float64(p)
	}
	return 1 / result
}

func main() {
	maxN := 2
	maxTotient := totient(2)
	for n := 3; n <= 1000000; n++ {
		t := totient(n)
		if t > maxTotient {
			maxN = n
			maxTotient = t
		}
	}
	fmt.Println(maxN)
}
