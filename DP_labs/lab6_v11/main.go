package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	arrayLen = 5
)

func getInt() int {
	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Print("Enter int: ")
		value, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("Error reading stdin: ", err)
			continue
		}

		converted, err := strconv.Atoi(value[:len(value)-1])
		if err != nil {
			fmt.Println("Error converting int: ", err)
			continue
		}

		return converted
	}
}

type Array struct {
	array []int
}

func NewArray() Array {
	return Array{array: make([]int, arrayLen)}
}

func (arr *Array) FIll() {
	for i := 0; i < arrayLen; i++ {
		arr.array[i] = getInt()
	}
}

func (arr Array) Print() {
	fmt.Println(arr.array)
}

func (arr Array) findFirstMaxPos() int {
	maxItem := arr.array[len(arr.array)-1]
	maxItemPos := len(arr.array) - 1

	for i := len(arr.array) - 1; i > 0; i-- {
		if arr.array[i] >= maxItem {
			maxItem = arr.array[i]
			maxItemPos = i
		}
	}

	return maxItemPos
}

func (arr *Array) prependBeforeZeros(n int) {
	newArr := []int{}
	for i := 0; i < len(arr.array); i++ {
		if arr.array[i] == 0 {
			newArr = append(newArr, n)
		}
		newArr = append(newArr, arr.array[i])
	}

	arr.array = newArr
}

func main() {
	arr := NewArray()
	arr.FIll()
	arr.Print()
	fmt.Println("Position of first max item:", arr.findFirstMaxPos())
	fmt.Println("Enter value to prepend before zeros:")
	value := getInt()
	arr.prependBeforeZeros(value)
	arr.Print()
}
