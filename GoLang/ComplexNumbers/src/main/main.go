package main

import (
	"fmt"
	"pkg/ComplexNumber"
)

func main() {
	compNum := ComplexNumber.Create(1, 2)
	compNumInverse := ComplexNumber.Inverse()
	fmt.Println("Complex number = ", compNum, "Its Inverse = ", compNumInverse)
}
