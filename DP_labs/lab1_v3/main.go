package main

import "fmt"

// ####|
// ####|
// ####|
// ####|
// ————+————
//     |
//     |
//     |
//     |

func main() {
	var x, y float32

	for {
		fmt.Print("Please, enter x and y: ")
		if _, err := fmt.Scanf("%f %f", &x, &y); err != nil {
			fmt.Println("Invalid input")
		}

		if x <= 0 && y >= 0 {
			fmt.Println("Inside zone")
		} else {
			fmt.Println("Outside zone")
		}
	}
}
