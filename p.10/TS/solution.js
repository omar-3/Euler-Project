function prime_sieve(n) {
    var sieve = new Array(n + 1).fill(true);
    sieve[0] = false;
    sieve[1] = false;
    for (var elem = 2; elem < Math.ceil(Math.sqrt(n)); elem++) {
        if (sieve[elem]) {
            for (var multiple = elem * elem; multiple < n + 1; multiple += elem) {
                sieve[multiple] = false;
            }
        }
    }
    return sieve.reduce(function (primes, isPrime, index) {
        if (isPrime) {
            primes.push(index);
        }
        return primes;
    }, []);
}
function main() {
    var primes = prime_sieve(2000000);
    var total = primes.reduce(function (sum, prime) { return sum + prime; }, 0);
    console.log(total);
}
main();
