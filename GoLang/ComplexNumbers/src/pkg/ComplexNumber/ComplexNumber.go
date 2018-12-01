package ComplexNumber

import(
	"math"
)

func Conjugate(compNum complex128) complex128 {
	var imagPart complex128
	imagPart = complex(0, 2*(imag(compNum)))
	compNumConjugate := compNum - imagPart
	return (compNumConjugate)
}

func Inverse(compNum complex128) complex128{
	compInverse := 1/compNum
	return (compInverse)
}

func Magnitude(compNum complex128) float64{
	fMagnitude := math.Sqrt(math.Pow(real(compNum),2) + math.Pow(imag(compNum),2))
	return fMagnitude
}

func PolarAngleRadian(compNum complex128) float64{
	fRadianPolarAngle := math.Atan(imag(compNum)/real(compNum))
	return fRadianPolarAngle
}

func PolarAngleDegree(compNum complex128) float64{
	fRadianPolarAngle := PolarAngleRadian(compNum)
	fDegreePolarAngle := ((180 * fRadianPolarAngle) / (22/7))
	return fDegreePolarAngle
}

func Create(realNum, imgNum float64) complex128 {
	return complex(realNum, imgNum)
}

