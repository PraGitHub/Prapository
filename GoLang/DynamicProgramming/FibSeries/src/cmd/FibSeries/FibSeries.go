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

	fmt.Println("Called SimpleNonRecursive")
	fmt.Println(time.Now())
	fmt.Println("SimpleNonRecursive : ", Methods.SimpleNonRecursive(n))
	fmt.Println(time.Now())

	fmt.Println("Called MemoRecursive")
	fmt.Println(time.Now())
	fmt.Println("MemoRecursive : ", Methods.MemoRecursive(n, true))
	fmt.Println(time.Now())

	fmt.Println("Called SimpleRecursive")
	fmt.Println(time.Now())
	fmt.Println("SimpleRecursive : ", Methods.SimpleRecursive(n))
	fmt.Println(time.Now())
}
