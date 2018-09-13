package main

import "fmt"

// ####|####
// ### | ###
// ##  |  ##
// #   |   #
// ————+————
// #   |   #
// ##  |  ##
// ### | ###
// ####|####

const edgeLen = 4

func main() {
	var x, y float32

	for {
		fmt.Print("Please, enter x and y: ")
		if _, err := fmt.Scanf("%f %f", &x, &y); err != nil {
			fmt.Println("Invalid input")
		}

		if x <= y-edgeLen || x >= y+edgeLen || x <= -y-edgeLen || x >= -y+edgeLen {
			fmt.Println("Inside zone")
		} else {
			fmt.Println("Outside zone")
		}
	}
}
