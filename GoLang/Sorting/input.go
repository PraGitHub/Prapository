package main

import (
	"fmt"
	"math/rand"
)

func main() {
	k := 0
	i := 0
	for i < 1000 {
		i++
		k++
		fmt.Print(rand.Intn(10000))
		fmt.Print(" ")
		if k == 20 {
			k = 0
			fmt.Println()
		}
	}
}
