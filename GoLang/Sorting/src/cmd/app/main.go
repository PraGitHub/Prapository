package main

import(
	"fmt"
	"pkg/Methods"
)

func main(){
	fmt.Println("Sorting app started")

	n := 0
	arr := make([]int,0)
	
	fmt.Println("Enter n = ")
	fmt.Scanf("%d",&n)

	for i:=0 ; i < n ; i++{
		
	}

	Methods.MergeSort();
	Methods.QuickSort();
}