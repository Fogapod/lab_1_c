package main

import (
	"fmt"
	"io/ioutil"
	"regexp"
)

func main() {
	wordRegex := regexp.MustCompile(`[A-z]+`)
	text, err := ioutil.ReadFile("Mark.Twain-Tom.Sawyer.txt")
	if err != nil {
		panic(err)
	}

	var sumOfWordCharacters float32
	words := wordRegex.FindAllStringSubmatch(string(text), -1)
	for _, word := range words {
		sumOfWordCharacters += float32(len(word[0]))
	}

	fmt.Println("Average number of symbols in word:", sumOfWordCharacters/float32(len(words)))
}
