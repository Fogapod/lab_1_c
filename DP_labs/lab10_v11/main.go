package main

import "fmt"

func reversePrint(arr []int, index int) {
	if index < len(arr)-1 {
		reversePrint(arr, index+1)
	}

	fmt.Printf("%d ", arr[index])
}

func main() {
	reversePrint([]int{1, 2, 3, 4, 5}, 0)
	fmt.Println()
}
