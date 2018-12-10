package main

import(
	"fmt"
	"pkg/Methods"
)

func main(){
	fmt.Println("FindTheFaulty App Started ...")
	fmt.Println("Example input : 1 1 1 1 1 0 1 1 1 1 - 10  bits, it should have only one 0 or could also be all 1s")
	/*
	Methods.Method334()
	Methods.Method343()
	Methods.Method55()

	var sliceResults []int
	sliceResults = append(sliceResults, 1)
	sliceResults = append(sliceResults, 1)
	fmt.Println("len of sliceResults = ",len(sliceResults))
	fmt.Println("sliceResults = ",sliceResults)
	*/
	var sliceResults []int
	var t,x int

	fmt.Println("No. of testcases : ")
	fmt.Scanf("%d",&t)

	for it:=0 ; it < t ; it++{
		fmt.Printf("Enter Input %d\n", it+1)

		for i:=0 ; i <= 10 ; i++{
			if(i == 0){
				fmt.Scanf("%d",&x)
				continue
				//need to do this
			}
			fmt.Scanf("%d",&x)
			sliceResults = append(sliceResults, x)
			//fmt.Println(sliceResults)
		}
		fmt.Println("Given input = ",sliceResults)
		fmt.Println("Method334 = ",Methods.Method334(sliceResults))
		fmt.Println("Method343 = ",Methods.Method343(sliceResults))
		fmt.Println("Method55 = ",Methods.Method55(sliceResults))
		sliceResults = nil
	}
	
}