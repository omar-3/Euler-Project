package main

import (
	"bufio"
	"math"
	"os"
	"strconv"
	"strings"
)

func transpose(matrix [][]int) [][]int {
	n := len(matrix)
	transpose_matrix := make([][]int, n)

	for i := 0; i < n; i++ {
		transpose_matrix[i] = make([]int, n)
		for j := 0; j < n; j++ {
			transpose_matrix[i][j] = matrix[j][i]
		}
	}
	return transpose_matrix
}

func reverse(arr []int) []int {
	length := len(arr)
	reversed_arr := make([]int, length)
	i := 0
	j := length - 1

	for i < j {
		reversed_arr[i], reversed_arr[j] = arr[j], arr[i]
		i, j = i+1, j-1
	}

	return reversed_arr
}

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		panic("Error opening file")
	}
	defer file.Close()

	var matrix [][]int
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := strings.Fields(scanner.Text())
		row := make([]int, len(line))

		for i, number := range line {
			integer, err := strconv.Atoi(number)
			if err != nil {
				panic("Can't convert string to integer")
			}
			row[i] = integer
		}
		matrix = append(matrix, row)
	}

	window_size := 4
	max_prod := int(math.Inf(-1))

	// horizontal windows
	for _, row := range matrix {
		for i := 0; i < len(row)-window_size+1; i++ {
			window := row[i : i+window_size]
			product := 1
			for _, elem := range window {
				product *= elem
			}
			if product > max_prod {
				max_prod = product
			}
		}
	}

	// vertical windows
	transposed_matrix := transpose(matrix)
	for _, col := range transposed_matrix {
		for i := 0; i < len(col)-window_size+1; i++ {
			window := col[i : i+window_size]
			product := 1
			for _, elem := range window {
				product *= elem
			}
			if product > max_prod {
				max_prod = product
			}
		}
	}

	// right diagonals
	for i := 0; i < len(matrix)-window_size+1; i++ {
		for j := 0; j < len(matrix)-window_size+1; j++ {
			window := make([]int, window_size)
			for k := 0; k < window_size; k++ {
				window = append(window, matrix[i+k][j+k])
			}
			product := 1
			for _, elem := range window {
				product *= elem
			}
			if product > max_prod {
				max_prod = product
			}
		}
	}

	// left diagonals
	reversed_matrix := make([][]int, len(matrix))
	for i, row := range matrix {
		reversed_matrix[i] = make([]int, len(row))
		reversed_matrix[i] = reverse(row)
	}

	for i := 0; i < len(matrix)-window_size+1; i++ {
		for j := 0; j < len(matrix)-window_size+1; j++ {
			window := make([]int, window_size)
			for k := 0; k < window_size; k++ {
				window = append(window, reversed_matrix[i+k][j+k])
			}
			product := 1
			for _, elem := range window {
				product *= elem
			}
			if product > max_prod {
				max_prod = product
			}
		}
	}
}
