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
			m[i][j] = (rowCount+colCount)/2 - abs(i-j)
		}
	}
}

func printMatrix(m [][]int) {
	for _, s := range m {
		fmt.Println(s)
	}
}

func sortLowerRow(m [][]int) [][]int {
	sort.Slice(m[rowCount-1], func(i int, j int) bool {
		return m[rowCount-1][i] > m[rowCount-1][j]
	})

	return m
}

func main() {
	matrix := make([][]int, rowCount)

	fillMatrix(matrix)
	fmt.Println("Input:")
	printMatrix(matrix)
	fmt.Println("Sorted:")
	printMatrix(sortLowerRow(matrix))
}
