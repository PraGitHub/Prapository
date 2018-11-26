package ComplexNumber

var Data complex128

func Inverse() complex128 {
	var imagPart complex128
	imagPart = complex(0, 2*(imag(Data)))
	compNumInverse := Data - imagPart
	return (compNumInverse)
}

func Create(realNum, imgNum float64) complex128 {
	Data = complex(realNum, imgNum)
	return Data
}
