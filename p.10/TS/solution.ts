function prime_sieve(n: number): Array<number> {
  const sieve: Array<boolean> = new Array(n + 1).fill(true);
  sieve[0] = false;
  sieve[1] = false;
  for (let elem = 2; elem < Math.sqrt(n); elem++) {
    if (sieve[elem]) {
      for (let multiple = elem * elem; multiple < n + 1; multiple += elem) {
        sieve[multiple] = false;
      }
    }
  }
  return sieve.reduce((primes, isPrime, index) => {
    if (isPrime) { primes.push(index); }
    return primes;
  }, [] as Array<number>);
}

function main() {
  const primes = prime_sieve(2000_000);
  const total = primes.reduce((sum: number, prime: number) => sum + prime, 0);
  console.log(total);
}

main();
