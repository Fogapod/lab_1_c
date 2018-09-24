package main

import (
	"fmt"
	"math"
)

const (
	a = 0
	b = math.Pi / 2
	kStep = 0.1
	n = 3
)

var (
	k = 0.1
)

func f(x float64) float64 {
	return 1 - k * math.Pow(math.Pow(math.Sin(x), 2), 0.5)
}

func integral(left, right float64) float64 {
	x := []float64{}
	h := (b-a)/n
	z := h / 5
	for i := left; i < right; i += z {
		x = append(x, i)
	}

	return z / 140 * (41*f(x[0]) + 216*f(x[1]) + 27*f(x[2]) + 272*f(x[3]) + 27*f(x[4]) + 216*f(x[5])  + 41*f(x[6]))
}

func main() {
	for i := 0; i < n+1; i++ {
		fmt.Println(integral(a, b))
		k += kStep
	}
}
