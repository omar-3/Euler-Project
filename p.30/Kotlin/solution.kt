import kotlin.math.pow

val digitPowers: List<Int> = List(10) {d -> d.toDouble().pow(5).toInt() }

fun isSumOfFifthPowers(num: Int): Boolean {
    var tmp = num
    var sum = 0
    while (tmp > 0) {
        val digit = tmp % 10
        sum += digitPowers[digit]
        tmp /= 10
    }
    return sum == num
}

fun sumOfFifthPowerNumbers(): Long {
    return (2..999_999)
        .filter { isSumOfFifthPowers(it) }
        .map { it.toLong() }
        .sum()
}

fun main() {
    val answer = sumOfFifthPowerNumbers()
    println("$answer")
}
