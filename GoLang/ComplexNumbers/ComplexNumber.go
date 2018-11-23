package ComplexNumber

var compNum complex128

func Inverse() complex128 {
	var imagPart complex128
	imagPart = complex(0, 2*(imag(compNum)))
	compNumInverse := compNum - imagPart
	return (compNumInverse)
}

func Create(compInput complex128) {
	compNum = compInput
}
