fun main() {
	val squareNumbers = (1..100).map { it * it }
	val subsetSize = squareNumbers.size / 2
	
	// Initialize the list to keep track of sums
	val sumTracking = MutableList<MutableMap<Int, Boolean>>(subsetSize + 1){ mutableMapOf() }
	sumTracking[0][0] = true

	squareNumbers.forEach { square ->
		for (count in subsetSize - 1 downTo 0) {
			sumTracking[count].keys.toList().forEach { existingSum ->
				val newSum = square + existingSum
				sumTracking[count + 1][newSum] = !sumTracking[count + 1].containsKey(newSum) &&
												sumTracking[count].getOrDefault(existingSum, false);
			}
		}
	}

	val uniqueSumTotal = sumTracking[subsetSize].filter { it.value }.keys.sum()
	println(uniqueSumTotal)
}
