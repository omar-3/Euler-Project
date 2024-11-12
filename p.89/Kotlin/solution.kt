import java.io.File
import java.lang.Integer.MAX_VALUE

fun romanToInt(roman: String): Int {
  val romanValues = mapOf(
    'I' to 1, 'V' to 5, 'X' to 10, 'L' to 50,
    'C' to 100, 'D' to 500, 'M' to 1000
  )

  var total = 0
  var prevValue = MAX_VALUE

  for (char in roman) {
    val value = romanValues[char] ?: 0
    if (value > prevValue) {
      total += value - 2 * prevValue
    } else {
      total += value
    }
    prevValue = value
  }

  return total
}

fun intToMinimalRoman(num: Int): String {
  val mappings = listOf(
    1000 to "M", 900 to "CM", 500 to "D", 400 to "CD",
    100 to "C", 90 to "XC", 50 to "L", 40 to "XL",
    10 to "X", 9 to "IX", 5 to "V", 4 to "IV", 1 to "I"
  )

  val result = StringBuilder()
  var number = num

  for ((value, numeral) in mappings) {
    while (number >= value) {
      result.append(numeral)
      number -= value
    }
  }

  return result.toString()
}


fun calculateSavings(filename: String): Int {
  var savings = 0

  File(filename).forEachLine { line ->
    val roman = line.trim()
    val originalLength = roman.length
    val minimalLength = intToMinimalRoman(romanToInt(roman)).length
    savings += originalLength - minimalLength
  }

  return savings
}

fun main() {
  val filename = "roman.txt"
  val savings = calculateSavings(filename)
  println("Total characters saved : $savings")
}
