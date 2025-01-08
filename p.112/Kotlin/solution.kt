fun Long.digits(): List<Int> {
    if (this == 0L) return listOf(0)
    var x = this
    val result = mutableListOf<Int>()
    while (x > 0) {
        result.add((x % 10).toInt())
        x /= 10
    }
    result.reverse()
    return result
}

fun isIncreasing(num: Long): Boolean {
    val digs = num.digits()
    return digs.zipWithNext().all { (a, b) -> a <= b}
}

fun isDecreasing(num: Long): Boolean {
    val digs = num.digits()
    return digs.zipWithNext().all { (a, b) -> a >= b}
}

fun isBouncy(num: Long): Boolean {
    return !(isIncreasing(num) || isDecreasing(num))
}

fun main() {
    var n = 99L
    var bouncyCount = 0L

    while (true) {
        n++
        if (isBouncy(n)) {
            bouncyCount++
        }

        if (bouncyCount * 100 == 99L * n) {
            println(n)
            break
        }
    }
}
