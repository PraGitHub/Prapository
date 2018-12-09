package main

import (
	"fmt"
	"pkg/Methods"
	"time"
)

func main() {
	fmt.Println("FibSeries App Started...")
	var n int
	fmt.Println("Enter n value = ")
	fmt.Scanf("%d", &n)

	fmt.Println(time.Now(), " Called SimpleRecursive")
	fmt.Println(time.Now(), " SimpleRecursive : ", Methods.SimpleRecursive(n))

	fmt.Println(time.Now(), " Called SimpleNonRecursive")
	fmt.Println(time.Now(), " SimpleNonRecursive : ", Methods.SimpleNonRecursive(n))

	fmt.Println(time.Now(), " Called MemoRecursive")
	fmt.Println(time.Now(), " MemoRecursive : ", Methods.MemoRecursive(n, true))
}
