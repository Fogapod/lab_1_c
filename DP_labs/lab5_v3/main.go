package main

import (
	"fmt"
	"io/ioutil"
	"regexp"
	"strings"
)

func main() {
	wordRegex := regexp.MustCompile(`\w+`)
	text, err := ioutil.ReadFile("Mark.Twain-Tom.Sawyer.txt")
	if err != nil {
		panic(err)
	}

	wordFreq := map[string]int{}
	for _, word := range wordRegex.FindAllStringSubmatch(string(text), -1) {
		word := strings.ToLower(word[0])
		if _, ok := wordFreq[word]; ok {
			wordFreq[word]++
		} else {
			wordFreq[word] = 1
		}
	}

	fmt.Printf("Frequency of 'the' in text: %d\n", wordFreq["the"])
	fmt.Printf("Frequency of 'now' in text: %d\n", wordFreq["now"])
}
