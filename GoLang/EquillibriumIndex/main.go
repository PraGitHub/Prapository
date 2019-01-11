package main

import(
	"fmt"
)

func main(){
	n := 0
	arr := make([]int,0)
	sum := 0

	fmt.Println("Enter n = ")
	fmt.Scanf("%d",&n)
	fmt.Println("enter elements of array : ")
	for i:=0;i<=n;i++{
		var x int
		fmt.Scanf("%d",&x)

		if i == 0{
			continue
		}
		arr = append(arr,x)
		sum = sum + x
	}

	fmt.Println("arr = ",arr)

	right_sum := sum
	left_sum := 0
	equillibrium_index := -1

	for i:=0;i<n-1;i++{
		fmt.Println("left_sum = ",left_sum,";right_sum = ",right_sum)
		left_sum = left_sum + arr[i]
		right_sum = right_sum - arr[i]
		if left_sum == right_sum - arr[i+1]{
			equillibrium_index = i + 1
			break
		}
	}
	fmt.Println("equillibrium_index = ",equillibrium_index)
}