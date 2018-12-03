package main

import(
	"fmt"
	"pkg/Methods"
)

func main(){
	fmt.Println("FindTheFaulty App Started ...")
	Methods.Method334()
	Methods.Method343()
	Methods.Method55()

	var sliceResults []int
	sliceResults = append(sliceResults, 1)
	sliceResults = append(sliceResults, 1)
	fmt.Println("len of sliceResults = ",len(sliceResults))
	fmt.Println("sliceResults = ",sliceResults)
}