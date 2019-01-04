package main

import (
	"fmt"
	"pkg/Methods"
)

func main() {
	fmt.Println("Sorting app started")

	n := 0
	x := 0
	var arr []int = nil

	fmt.Println("Enter n = ")
	fmt.Scanf("%d", &n)
	fmt.Println("Enter numbers : ")

	for i := 0; i <= n; i++ {
		fmt.Scanf("%d", &x)
		if i == 0 {
			continue
		}
		arr = append(arr, x)
	}

	fmt.Println("Given array = ", arr)

	fmt.Println("Calling Merge sort")
	arr = Methods.MergeSort(arr)
	fmt.Println("sorted arr = ", arr)

	fmt.Println("Calling Quick sort")
	arr = Methods.QuickSort(arr)
	fmt.Println("sorted arr = ", arr)
}
