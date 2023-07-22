function primeFactors(n: number): Array<number> {
  let factors: Array<number> = [];
  for (let i = 2; i < Math.sqrt(n); i++) {
    while (n % i === 0) {
      factors.push(i);
      n = Math.floor(n / i);
    }
  }
  if (n > 1) { factors.push(n); }
  return factors;
}

function totientFunction(factors: Array<number>): number {
  let distinct_primes: Array<number> = factors.filter(
    (value, index, self) => self.indexOf(value) === index);
  let result: number = 1;
  for (let prime of distinct_primes) {
    result *= (1 - 1 / prime);
  }
  return 1 / result;
}

function main() {
  let value: number | undefined;
  let maxTotient: number = Number.NEGATIVE_INFINITY;
  for (let i = 2; i < 1000_000; i++) {
    let factors = primeFactors(i);
    let totientValue = totientFunction(factors);
    if (totientValue > maxTotient) {
      maxTotient = totientValue;
      value = i;
    }
  }
  console.log(`Number with maximum n/phi n is ${value} with ratio ${maxTotient}`);
}

main();
