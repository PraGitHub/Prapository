package Methods

import(
	"fmt"
)

func method3(slice3 []int)(int){
	if slice3[0] == 0 {
		return 1
	}
	if slice3[1] == 0 {
		return 2
	}
	if slice3[2] == 0{
		return 3
	}
	return 0
}

func method4(slice4 []int)(int){
	if slice4[0] == 0{
		return 1
	}
	if slice4[1] == 0{
		return 2
	}
	if slice4[2] == 0{
		return 3
	}
	if slice4[3] == 0{
		return 4
	}
	return 0
}

func  method5(slice5 []int)(int){
	if slice5[0] == 0{
		return 1
	}
	if slice5[1] == 0{
		return 2
	}
	if slice5[2] == 0{
		return 3
	}
	if slice5[3] == 0{
		return 4
	}
	if slice5[4] == 0{
		return 5
	}
	return 0
}

func Method334(slice10 []int)(int){
	fmt.Println("Method334 : ")

	var sum int = 0

	sum = method3(slice10[0:3])
	if sum > 0 {
		return sum + 1
	}

	sum = method3(slice10[3:6])
	if sum > 0 {
		return sum + 2
	}

	sum = method4(slice10[6:10])
	if sum > 0 {
		return sum + 3
	}

	return 0
}

func Method343(slice10 []int)(int){
	fmt.Println("Method343 : ")
	
	var sum int = 0

	sum = method3(slice10[0:3])
	if sum > 0 {
		return sum + 1
	}

	sum = method4(slice10[3:7])
	if sum > 0 {
		return sum + 2
	}

	sum = method3(slice10[7:10])
	if sum > 0 {
		return sum + 3
	}

	return 0
}

func Method55(slice10 []int)(int){
	fmt.Println("Method55 : ")
	
	var sum int = 0

	sum = method5(slice10[0:5])
	if sum > 0{
		return sum + 1
	}

	sum = method5(slice10[5:10])
	if sum > 0{
		return sum + 2
	}

	return 0
}