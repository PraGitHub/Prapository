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
	return 3
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
	return 4
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
	return 4
}

func Method334()(){
	fmt.Println("Method334 Started...")
	
	fmt.Println("Method334 Ended...")
}

func Method343()(){
	fmt.Println("Method343 Started...")

	fmt.Println("Method343 Ended...")
}

func Method55()(){
	fmt.Println("Method55 Started...")
	
	fmt.Println("Method55 Ended...")
}