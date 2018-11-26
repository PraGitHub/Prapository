package main

import(
	"fmt"
	"pkg/ComplexNumber"
)

func main(){
	var fReal, fImaginary float64
	fmt.Println("Complex Numbers App")
	fmt.Println("Enter the real part : ")
	fmt.Scan(&fReal)
	fmt.Println("Enter the imaginary part : ")
	fmt.Scan(&fImaginary)

	compNum := ComplexNumber.Create(fReal, fImaginary)
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