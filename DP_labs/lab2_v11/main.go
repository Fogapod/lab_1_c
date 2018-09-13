package main

import (
	"fmt"
	"math/rand"
)

const arrayLen = 25

func isPrime(n int) bool {
	for i := 2; i < n - 1; i++ {
		if n % i == 0 {
			return false
		}
	}

	return true
}

func findAllPrime(arr []int) []int {
	found := []int{}

	for i := 0; i < len(arr); i++ {
		if isPrime(arr[i]) {
			found = append(found, arr[i])
		}
	}

	return found
}

func main() {
	arr := []int{}
	for k := 0; k < 5; k++ {
		for i := 0; i < arrayLen; i++ {
			arr = append(arr, rand.Intn(100) + 1)
		}

		fmt.Printf("Generated array: %v\n", arr)
		fmt.Printf("Prime array:     %v\n\n", findAllPrime(arr))
	}
}
