import kotlin.math.sqrt

fun generatePrimes(limit: Int): List<Int> {
  val sieve = BooleanArray(limit) { true }
  sieve[0] = false
  sieve[1] = false

  for (i in 2..sqrt(limit.toDouble()).toInt()) {
    if (sieve[i]) {
      for (j in i * i until limit step i) {
        sieve[j] = false
      }
    }
  }

  return sieve.withIndex().filter { it.value }.map { it.index }
}

fun countExpressibleNumbers(limit: Int): Int {
  val primes = generatePrimes(limit)

  val primeSquares = primes.asSequence()
    .map { it.toLong() * it }
    .filter { it < limit }
  val primeCubes = primes.asSequence()
    .map { it.toLong() * it * it }
    .filter { it < limit }
  val primeFourths = primes.asSequence()
    .map { it.toLong() * it * it * it }
    .filter { it < limit }

    val isExpressible = BooleanArray(limit)

    for (square in primeSquares) {
      for (cube in primeCubes) {
        for (fourth in primeFourths) {
          val total = square + cube + fourth
          if (total >= limit) break
          isExpressible[total.toInt()] = true
        }
      }
    }


    return isExpressible.count { it }
}

fun main() {
  val limit = 50_000_000
  val result = countExpressibleNumbers(limit)
  println(result)
}
