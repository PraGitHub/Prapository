package main

import (
	"fmt"
	"pkg/ComplexNumber"
)

func main() {
	compNum := ComplexNumber.Create(1, 2)
	compNumConjugate := ComplexNumber.Conjugate(compNum)
	compNumInverse := ComplexNumber.Inverse(compNum)
	fMagnitude := ComplexNumber.Magnitude(compNum)
	fPolarAngleRadian := ComplexNumber.PolarAngleRadian(compNum)
	fPolarAngleDegree := ComplexNumber.PolarAngleDegree(compNum)

	fmt.Println("Complex number = ", compNum)
	fmt.Println("Inverse = ", compNumInverse)
	fmt.Println("Conjugate = ",compNumConjugate)
	fmt.Println("Magnitude = ",fMagnitude)
	fmt.Println("Polar angle in radians = ",fPolarAngleRadian)
	fmt.Println("Polar angle in degrees = ",fPolarAngleDegree)
}
