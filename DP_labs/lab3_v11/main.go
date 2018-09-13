package main

import (
	"fmt"
	"sort"
)

const (
	rowCount     = 8
	colCount     = 8
	numberToTest = 2
)

func abs(a int) int {
	if a < 0 {
		return -a
	}

	return a
}

func fillMatrix(m [][]int) {
	for i := 0; i < rowCount; i++ {
		m[i] = make([]int, colCount)
		for j := 0; j < colCount; j++ {
			m[i][j] = abs(j-i) + 1
		}
	}
}

func printMatrix(m [][]int) {
	for _, s := range m {
		fmt.Println(s)
	}
}

func transpose(m [][]int) [][]int {
	result := make([][]int, len(m[0]))
	for i := range result {
		result[i] = make([]int, len(m))
	}

	for y, s := range m {
		for x, e := range s {
			result[x][y] = e
		}
	}

	return result
}

func sortCols(m [][]int) [][]int {
	temp := transpose(m)
	for k := 0; k < colCount; k++ {
		sort.SliceStable(temp[k], func(i int, j int) bool {
			return temp[k][i] < temp[k][j]
		})
	}

	return transpose(temp)
}

func main() {
	matrix := make([][]int, rowCount)

	fillMatrix(matrix)
	fmt.Println("Input:")
	printMatrix(matrix)
	fmt.Println("Sorted:")
	printMatrix(sortCols(matrix))
}
