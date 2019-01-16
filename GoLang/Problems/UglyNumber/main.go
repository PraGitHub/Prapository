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
		fmt.Println(n," is ugly")
		return true
	}
	fmt.Println(n," is not ugly")
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

func naive_method(n int)(int){
	i := 15
	count := 10
	arr := [...]int{1,2,3,4,5,6,8,9,10,12}

	if n <= 10{
		//fmt.Println("Output : ",arr[n-1])
		return arr[n-1]
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
			//fmt.Println("Output : ",i)
			break
		}
		i = i + 1
	}
	return i
}

func min(a,b,c int)(int){
	if a<=b && a<=c{
		return a
	}
	if b<=c{
		return b
	}
	return c
}

func dynamic_method(n int)(int){
	if n == 1{
		return 1
	}
	arr := make([]int,n)
	arr[0] = 1
	index_ugly := 1
	index_2 := 0
	index_3 := 0
	index_5 := 0
	last_2 := 2
	last_3 := 3
	last_5 := 5
	for i:=1;i<n;i++{
		last_2 = last_2*arr[index_2]
		last_3 = last_3*arr[index_3]
		last_5 = last_5*arr[index_5]
		ugly_num := min(last_2,last_3,last_5)
		arr[index_ugly] = ugly_num
		index_ugly = index_ugly + 1
		if ugly_num == last_2{
			index_2 = index_2 + 1	
		}
		if ugly_num == last_3{
			index_3 = index_3 + 1	
		}
		if ugly_num == last_5{
			index_5 = index_5 + 1	
		}
	}
	return arr[n-1]
}

func main()(){
	var n int

	fmt.Println("Enter n : ")
	fmt.Scanf("%d",&n)
	fmt.Println("given n = ",n)

	fmt.Println("Output by naive_method = ",naive_method(n))
	
	fmt.Println("Output by dynamic_method = ",dynamic_method(n))
}
