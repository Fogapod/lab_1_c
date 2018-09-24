package main

import (
	"fmt"
)

const (
	rowCount = 8
	colCount = 8
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
			m[i][j] = abs(j - i) + 1
		}
	}
}

func printMatrix(m [][]int) {
	result := ""
	for i := 0; i < rowCount; i++ {
		result += "["
		for j := 0; j < colCount; j++ {
			result += fmt.Sprintf("%d", m[i][j])
			if j != colCount - 1 {
				result += " "
			} else {
				result += "]\n"
			}
		}
	}

	fmt.Print(result)
}

func makeArray(m [][]int) []int {
	arr := make([]int, rowCount)
	for i := 0; i < rowCount; i++ {
		for j := 0; j < colCount; j++ {
			if m[i][j] % numberToTest == 0 {
				arr[i] += m[i][j]
			}
		}
	}

	return arr
}

func main() {
	matrix := make([][]int, rowCount)

	fillMatrix(matrix)
	fmt.Println("Input:")
	printMatrix(matrix)
	fmt.Println("Result:", makeArray(matrix))
}
