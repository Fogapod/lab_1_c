package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
)

func main() {
	emailRegex := regexp.MustCompile(`[\w.\-]+@([\w\d]+\.)+[\w\d]{2,}`)

	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Print("Enter email: ")
		userInput, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("Error reading input")
			continue
		}

		if emailRegex.MatchString(userInput[:len(userInput)-1]) {
			fmt.Println("Correct format")
		} else {
			fmt.Println("Wrong format")
		}
	}
}
