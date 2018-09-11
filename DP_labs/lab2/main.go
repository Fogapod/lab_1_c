package main

import (
	"fmt"
	"math/rand"
)

const N = 25

func main() {
	var arr [N]int
	for k := 0; k < 5; k++ {
		for i := 0; i < N; i++ {
			arr[i] = rand.Intn(100) + 1
		}

		fmt.Printf("Generated array: %v\n", arr)

		j := 0;

		for i := 0; i < N; i++ {
			num := arr[i]
			lastDigit := num % 10

			for num >= 10 {
				num /= 10
			}

			if arr[i] > 9 && num == lastDigit {
				continue
			} else {
				arr[j] = arr[i]
				j++
			}
		}

		for ; j < N; j++ {
			arr[j] = -1 // array can't include -1 so it indicates null value
		}

		fmt.Printf("Sorted array:    %v\n\n", arr)
	}
}
