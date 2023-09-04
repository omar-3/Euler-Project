package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	x, y float64
}

type Triangle [3]Point

func parseLine(line string) (Triangle, error) {
	parts := strings.Split(line, ",")
	if len(parts) != 6 {
		return Triangle{}, fmt.Errorf("invalid input line: %s", line)
	}
	var triangle Triangle
	for i:= 0; i < 3; i++ {
		x, err := strconv.ParseFloat(parts[2*i], 64)
		if err != nil {
			return Triangle{}, fmt.Errorf("invalud x coordinates: %s", parts[2*i])
		}

		y, err := strconv.ParseFloat(parts[2*i + 1], 64)
		if err != nil {
			return Triangle{}, fmt.Errorf("invalid y coordinates: %s", parts[2*i+1])
		}

		triangle[i] = Point{x, y}
	}
	return triangle, nil
}

func triangleArea(t Triangle) float64 {
	return 0.5 * math.Abs(t[0].x * (t[1].y - t[2].y) + t[1].x * (t[2].y - t[0].y) + t[2].x * (t[0].y - t[1].y))
}

func originInTriangle(t Triangle) bool {
	totalArea := triangleArea(t)
	t1 := Triangle{{0,0}, t[1], t[2]}
	t2 := Triangle{{0,0}, t[0], t[2]}
	t3 := Triangle{{0,0}, t[0], t[1]}
	return totalArea == triangleArea(t1) + triangleArea(t2) + triangleArea(t3)
}

func main() {
	file, err := os.Open("../0102_triangles.txt")
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		return
	}
	defer file.Close()

	count := 0
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		t, err := parseLine(scanner.Text())
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			continue
		}
		if originInTriangle(t) {
			count++
		}
	}
	fmt.Println(count)
}
