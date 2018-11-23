package main

import (
	"fmt"
)

func Inverse(compNum complex128) complex128 {
	var imagPart complex128
	imagPart = complex(0, 2*(imag(compNum)))
	compNumInverse := compNum - imagPart
	return (compNumInverse)
}

func main() {
	compNum := 1 + 2i
	compNumInverse := Inverse(compNum)
	fmt.Println(compNumInverse)
	fmt.Println(compNum + compNumInverse)
	fmt.Println(compNum - compNumInverse)
	fmt.Println(compNum * compNumInverse)
	fmt.Println(compNum / compNumInverse)
	fmt.Println(1 / compNum)
}
