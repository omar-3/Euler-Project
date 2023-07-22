function primeFactors(n) {
    var factors = [];
    for (var i = 2; i < Math.sqrt(n); i++) {
        while (n % i === 0) {
            factors.push(i);
            n = Math.floor(n / i);
        }
    }
    if (n > 1) {
        factors.push(n);
    }
    return factors;
}
function totientFunction(factors) {
    var distinct_primes = factors.filter(function (value, index, self) { return self.indexOf(value) === index; });
    var result = 1;
    for (var _i = 0, distinct_primes_1 = distinct_primes; _i < distinct_primes_1.length; _i++) {
        var prime = distinct_primes_1[_i];
        result *= (1 - 1 / prime);
    }
    return 1 / result;
}
function main() {
    var value;
    var maxTotient = Number.NEGATIVE_INFINITY;
    for (var i = 2; i < 1000000; i++) {
        var factors = primeFactors(i);
        var totientValue = totientFunction(factors);
        if (totientValue > maxTotient) {
            maxTotient = totientValue;
            value = i;
        }
    }
    console.log("Number with maximum n/phi n is ".concat(value, " with ratio ").concat(maxTotient));
}
main();
