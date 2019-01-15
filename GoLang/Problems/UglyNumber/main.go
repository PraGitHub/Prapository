package main

import(
	"fmt"
)

func is_ugly(n int)(bool){
	num := n
	num = divide_n_by_max_power_of_k(num,2)
	num = divide_n_by_max_power_of_k(num,3)
	num = divide_n_by_max_power_of_k(num,5)
	if num == 1{
		//fmt.Println(n," is ugly")
		return true
	}
	//fmt.Println(n," is not ugly")
	return false
}

func divide_n_by_max_power_of_k(n,k int)(int){
	//fmt.Println("divide_n_by_max_power_of_k :: input = ",n)
	for n % k == 0{
		n = n / k
	}
	//fmt.Println("divide_n_by_max_power_of_k :: output = ",n)
	return n
}

func main()(){
	var n int
	i := 15
	count := 6
	arr := [...]int{1,2,3,4,5,6,8,9,10,12}

	fmt.Println("Enter n : ")
	fmt.Scanf("%d",&n)
	fmt.Println("given n = ",n)

	if n <= 10{
		fmt.Println("Output : ",arr[n-1])
		return
	}

	for true{
		if !(i % 2 == 0 || i % 3 == 0 || i % 5 == 0){
			i = i + 1
			continue
		}
		if is_ugly(i){
			count = count + 1
		}
		if count == n{
			fmt.Println("Output : ",i)
			return
		}
		i = i + 1
	}
}
